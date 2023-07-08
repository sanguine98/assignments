#include "invertedIndex.h"

int main(int argc, char *argv[])
{
    //Check CLA's Passed or not
    if (argc == 1)
    {
        printf("Error : Invalid no.of arguments\nUsage ./inverted_index <file.txt> <file1.txt> ...\n");
        return FAILURE;
    }

    file_node_t *fhead = NULL;
    validate_n_store_filenames(&fhead, argv + 1);

    if (fhead == NULL)
    {
        printf("There is no valid files\nPlease pass the valid file\n");
        return FAILURE;
    }

    //Display the menu
}

void validate_n_store_filenames(file_node_t **fhead, char *filenames[])
{
    int i = 0, status;
    while (filenames[i] != NULL)
    {
        status = IsFileValid(filenames[i]);
        if (status == NOT_PRESENT)
        {
            printf("The file %s is not exist\n", filenames[i]);
        }
        else if (status == FILE_EMPTY)
        {
            printf("The file %s is an empty file\n", filenames[i]);
        }
        else
        {
            if (store_filenames_to_list(filenames[i], fhead) == REPEATED)
                printf("The file %s is repeated\n", filenames[i]);
            else
                printf("Successfull: Adding the file %s into the list\n", filenames[i]);
        }
        i++;
    }
}

int IsFileValid(char *f_name)
{
    //1. Check whether the file exist or not.
        //If the file not exist, then return NOT_PRESENT
    //2. If the file is exist, then check it is empty or not
        //If file empty, FILE_EMPTY

    //3. If file not empty, then return SUCCESS
}

file_node_t *create_node(char *fname)
{
    file_node_t *new = malloc(sizeof(file_node_t));
    if (new == NULL)
        //error
    new -> f_name = fname;  //Think how to store the filename
    new -> link = NULL;
    return new;
}

int store_filenames_to_list(char *f_name, file_node_t **head)
{
    file_node_t *new;
    //Insert at last operation
    if (*head == NULL)
    {
        new = create_node(f_name);
        *head = new;
        return SUCCESS;
    }

    file_node_t *temp = *head;

    while (temp != NULL)
    {
        // TODO: previous pointer, which points to previous node
        if (strcmp(temp -> f_name, f_name) != 0)
            temp = temp -> link;
        else
            return REPEATED;
    }
    prev -> link  = create_node(f_name);
    return SUCCESS;
}











