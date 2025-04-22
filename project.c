#include <stdio.h>
#include <string.h>
struct book
{
    int number[100];
    float price;
    char name[100];
    char author_name[100];
    char issue_date[15];
};

// Function prototypes
void password();
void welcome();
void exit_program();
int menu(struct book *library, int *bookcount);
int option(struct book *library, int *bookcount, int option);
void addbook(struct book *library, int *bookcount);
int search_a_book(struct book *library, int bookcount);
int search_by_author(struct book *library, int bookcount);
int show_info(struct book *library, int bookcount);
int delete_lastBook(struct book *library, int *bookcount);

int main()
{

    //int n;
    struct book library[1000];
    int bookcount = 0;

    password(); // func 1
    welcome();
    menu(library, &bookcount); // func 2

    return 0;


}
// func 1;
void password()
{

    int your_password;

    int  pass=123;

    char name[10];
    printf("\n\t\t\t\t Enter your name:");
    gets(name);

    printf("\n\t\t\t\t        PASSWORD:");
    scanf("%d", &your_password);

    switch( your_password)
    {
    case 123:

        break;
    default:
        printf("\nError! operator is not correct");
        password();
    }

}

void welcome()
{
    printf("\t\t\t********************************************************************************");
    printf("\n\t\t\t**************////////////////////////////////////////////**********************");
      printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>*************************");
    printf("\n\t\t\t***********//////////                               //////////******************");
    printf("\n\t\t\t************//////////    Welcome To EWU Library   //////////*******************");
    printf("\n\t\t\t************///////////                           /////////// ******************");
    printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>*************************");
      printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>*************************");
    printf("\n\t\t\t********************************************************************************\n\n");

}
void exit_program()
{


    printf("\t\t\t**********************************************************************************");
    printf("\n\t\t\t**************////////////////////////////////////////////**********************");
    printf("\n\t\t\t***********//////////            THANKS                //////////******************");
    printf("\n\t\t\t************//////////          FOR USING             //////////*******************");
    printf("\n\t\t\t************///////////        EWU LIBRARY           /////////// ******************");
    printf("\n\t\t\t********************                                      *************************");
    printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>****************************");
    printf("\n\t\t\t***********************************$$$*********************************************");

}
int menu(struct book *library, int *bookcount)
{
    int n;

    while (1)
    {
        printf("\n     \t\t\t\t      1. Add A Book.\n");
        printf("\t\t\t\t      2. Search A BOOK By Name.\n");
        printf("\t\t\t\t      3. Search A Book By Author Name.\n");
        printf("\t\t\t\t      4.Show All Info.\n");
        printf("\t\t\t\t      5.Delete Last book\n");
        printf("\t\t\t\t      6. Exit.\n");
        printf("\n\t\t\t\t      Please Enter your choice: ");
        scanf("%d", &n);

        if (n == 6)
        {
            exit_program();
            break;
        }
        else
        {
            option(library, bookcount, n);
        }
    }
}

int option(struct book *library, int *bookcount, int option)
{
    switch (option)
    {
    case 1:
        addbook(library, bookcount);
        break;
    case 2:
        search_a_book(library, *bookcount);
        break;
    case 3:
        search_by_author(library, *bookcount);
        break;
    case 4:
        show_info(library, *bookcount);
        break;
    case 5:
        delete_lastBook(library, bookcount);
        break;
    default:
        printf("\t\t\t\t\t\n\nCHOOSE ANYTHING BETWEEN 1-6.\n\n");
    }
}

void addbook(struct book *library, int *bookcount)
{
    struct book newbook;
    //here book is the struct and new book is added


    printf("\n\t\t\t**************////////////////////////////////////////////**********************");
    printf("\n\t\t\t***********//////////                               //////////******************");
    printf("\n\t\t\t************//////////        Add A Book.          //////////*******************");
    printf("\n\t\t\t************///////////                           /////////// ******************");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t************////////////////////////////////////////////******************** ");

    printf("\n\n\n\t\t\t                         ENTER BOOK NAME::");
    fflush(stdin);//buffer overflow
    gets(newbook.name);

    printf("\n\t\t\t\t                 Enter author name:");
    fflush(stdin); //go get rid of bug;
    gets(newbook.author_name);

    printf("\n\t\t\t\t                 Enter book Price: ");
    scanf("%f", &newbook.price);
    printf("\n\t\t\t\t                 Enter the date of issue DD/MM/YY:");
    scanf("%s", &newbook.issue_date);

    library[*bookcount]=newbook;//This line adds the new book to the book array at index bookcount.
    (*bookcount)++;
    printf("\n\t\t\t                      %d book has added successfully\n",*bookcount);
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n\n\n\n");

}
int search_a_book(struct book *library, int bookcount)
{
    char search_book[100];
    int found = 0;
    printf("\n\t\t\t**************////////////////////////////////////////////**********************");
    printf("\n\t\t\t***********//////////                               //////////******************");
    printf("\n\t\t\t************//////////       SEARCH A BOOK         ///////////******************");
    printf("\n\t\t\t************///////////                           /////////// ******************");
    printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>************************");
    printf("\n\t\t\t************////////////////////////////////////////////******************** ");


    printf("\n\n               \t\t\t\tEnter the book name to search: ");
    fflush(stdin);
    gets(search_book);

    for (int i = 0; i < bookcount; i++)
    {
        if (strcmp(library[i].name, search_book) == 0)
        {
            printf("\n\n\t\t\t\t      Book Founded:\n");
            printf("\t\t\t\t      Book Name: %s\n", library[i].name);
            printf("\t\t\t\t      Authors Name: %s\n", library[i].author_name);
            printf("\t\t\t\t      Date: %s\n", library[i].issue_date);
            printf("\t\t\t\t      Price: %.2f\n\n\n", library[i].price);
            printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>************************");
            found = 1;
        }
    }

    if (found==0)
    {
        printf("\t\t\t\tNO MATCH FOUND\n \t\t\t\tWE ARE SORRY");
    }
}

int search_by_author(struct book *library, int bookcount)
{
    char search_by_author[100];
    int found = 0;
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t***********//////////        SEARCH A BOOK          //////////****************");
    printf("\n\t\t\t************//////////            BY               ///////////****************");
    printf("\n\t\t\t************///////////      AUTHOR'S NAME        /////////// ****************");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");



    printf("\n\n\t\t\t\t      Enter the  name of Author to search: ");
    fflush(stdin);
    gets(search_by_author);

    for (int i = 0; i < bookcount; i++)
    {
        if (strcmp(library[i].author_name,search_by_author) == 0)
        {
            printf("\n\n\t\t\t\tBook Found:\n");
            printf("\t\t\t\tBook Name: %s\n", library[i].name);
            printf("\t\t\t\tAuthors Name: %s\n", library[i].author_name);
            printf("\t\t\t\tDate: %s\n", library[i].issue_date);
            printf("\t\t\t\tPrice: %.2f\n\n\n\n\n", library[i].price);
            found=1;//loop somossa
        }
    }


    if (found==0)
    {
        printf("\t\t\t\tNO MATCH FOUND\n \t\t\t\tWE ARE SORRY");
    }


}
int show_info(struct book *library, int bookcount)
{
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~>  \t  BOOKS     <~><~><~><~><~><~><~><~><~><~><~><~>\n");
    for (int i = 0; i < bookcount; i++)
    {

        printf("\n\t\t\t <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
        printf("\t\t\t                       \tBook Found:\n");
        printf("\t\t\t                       \tBook Name: %s\n", library[i].name);
        printf("\t\t\t                       \tAuthors Name: %s\n", library[i].author_name);
        printf("\t\t\t                       \tDate: %s\n", library[i].issue_date);
        printf("\t\t\t                       \tPrice: %.2f\n\n", library[i].price);
        printf("\n\t\t\t <~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");
    }
}


int delete_lastBook(struct book *library, int *bookcount)
{

    if (bookcount>0)
    {
        printf("\n\n\t\t\t\t      Book Deleted:\n");
        printf("\t\t\t\t      Deleted Book Name: %s\n", library[*bookcount-1].name);
        printf("\t\t\t\t      Authors Name: %s\n", library[*bookcount-1].author_name);
        printf("\t\t\t\t      Date: %s\n", library[*bookcount-1].issue_date);
        printf("\t\t\t\t      Price: %.2f\n\n\n", library[*bookcount-1].price);
        printf("\n\t\t\t********************<~><~><~><~><~><~><~><~><~><~><~><~>************************");
        (*bookcount)--;
    }


    else
    {
        printf("\t\t\t\tNO MATCH FOUND\n \t\t\t\tWE ARE SORRY");
    }
}
