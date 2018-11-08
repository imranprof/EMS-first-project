#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

///all global variable are here
char emid[40];
char emname[40];
char emdes[40];
char emdepart[40];
char emsallary[20];
char emaddress[60];
char emcont[40];
char emblg[10];

char semid[40];
char semname[40];
char semdes[40];
char semdepart[40];
char semsallary[20];
char semaddress[60];
char semcont[40];
char semblg[10];

///pototype all function are here
void display_did(char did[]);
void search_em(FILE *dtf, char aid[]);
void dis();
void show();
void add_data();
void add_another();
void edit();
void delet();
void mainmenu();

///this design function
void design();
///end pototype

/// this is the main menu
void mainmenu()
{
    int choice;
    char sid[40];

    system("COLOR 5F");         ///for coloring background and foreground

    design();

    printf("\n                               WELCOME TO EMPLOYEE MANAGEMENT SYSTEM                          \n\n");
    printf("                    ***********************MAIN MENU*************************\n\n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("                    \xB2\xB2            1.ADD NEW EMPLOYEE DATA                   \xB2\xB2 \n");
    printf("                    \xB2\xB2            2.SEARCH EMPLOYEE DATA BY ID              \xB2\xB2 \n");
    printf("                    \xB2\xB2            3.VIEW EMPLOYEE DATA                      \xB2\xB2 \n");
    printf("                    \xB2\xB2            4.EDIT EMPLOYEE DATA                      \xB2\xB2 \n");
    printf("                    \xB2\xB2            5.DELETE EMPLOYEE DATA                    \xB2\xB2 \n");
    printf("                    \xB2\xB2            0.EXIT                                    \xB2\xB2 \n");
    printf("                    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");

    printf("\n                             ENTER YOUR CHOICE: ");

    scanf("%d",&choice);

    if(choice==0)           //for close the program
    {
        exit(0);
    }

    if(choice==1)           //for calling add_data() function
    {
     add_data();
    }

    if (choice==3)         //for calling show() function for showing all data
    {
        show();
    }

    if(choice == 2) {       //for calling display_did() function for call search function for search by id
        system("cls");
        printf("\n\n                       DO YOU WANT TO SEARCH BY EMPLOYEE ID ?\n                             ENTER YOUR EMPLOYEE ID : ");
        scanf("%s", sid);
        display_did(sid);
    }

    if (choice ==4)         //for calling edit() function for edit employee data
    {
        edit();
    }

    if (choice == 5)        //for calling delet() function for delete employee data by id
    {
        delet();
    }
}

/// to add another data in exist file
void add_another(){

    char emid[40];
    char emname[40];
    char emdes[40];
    char emdepart[40];
    char emsallary[20];
    char emaddress[60];
    char emcont[40];
    char emblg[10];
    int n;
    char c, ch;

    FILE *fp;

    fp = fopen("Alldata.txt", "a");

    printf("\n           @@@@@@@@@@@@@@@@@@ YOU ARE GOING TO ADD ANOTHER EMPLOYEE DATA @@@@@@@@@@@@@@@@@@@@\n");
    printf("\n           ENTER EMPLOYEE ID : ");
    scanf("%s", emid);
    fprintf(fp, "\n%s", emid);

    printf("\n           ENTER EMPLOYEE NAME : ");
    scanf(" %[^\n]", emname);
    fprintf(fp, " %s", emname);

    printf("\n           ENTER EMPLOYEE DESIGNATION : ");
    scanf(" %[^\n]", emdes);
    fprintf(fp, " %s", emdes);

    printf("\n           ENTER EMPLOYEE DEPARTMENT : ");
    scanf(" %[^\n]", emdepart);
    fprintf(fp, " %s", emdepart);

    printf("\n           ENTER EMPLOYEE SALARRY: ");
    scanf(" %[^\n]", emsallary);
    fprintf(fp, " %s", emsallary);

    printf("\n           ENTER EMPLOYEE ADDRESS : ");
    scanf(" %[^\n]", emaddress);
    fprintf(fp, " %s", emaddress);

    printf("\n           ENTER EMPLOYEE CONTACT : ");
    scanf(" %[^\n]", emcont);
    fprintf(fp, " %s", emcont);

    printf("\n           ENTER EMPLOYEE BLOOD GROUP : ");
    scanf("%s",emblg);
    fprintf(fp, " %s", emblg);

    fclose(fp);
    printf("\n           @@@@@@@@@@@@@@@@@@ ANOTHER NEW EMPLOYEE DATA INSERTED SUCCESSFULLY @@@@@@@@@@@@@@@@@@\n");

    printf("\n     DO YOU ADD ANOTHER EMPLOYEE?                       ENTER 'y/n' : ");
    scanf("%c%c", &ch, &c);
    if(c == 'y'){
        system("cls");
        add_another();
    }
    else {
        system("cls");
        mainmenu();
    }


}

/// for add new employee data
void add_data(){
    int n,i;
    system("cls");
    char c, ch;

    printf("\n    FOR BACK                                           ENTER '0' ->\n");
    printf("    DO YOU WANT TO ADD NEW EMPLOYEE?                   ENTER '1' ->\n    DO YOU WANT TO ADD ANOTHER NEW EMPLOYEE?           ENTER '2' -> \n");
    scanf("%d", &n);
    if(n == 2) {
        add_another();

    }
    else if(n == 1){

        FILE *fp1;
        fp1 = fopen("Alldata.txt", "w");

        printf("\n           @@@@@@@@@@@@@@@@@@ YOU ARE GOING TO ADD NEW EMPLOYEE DATA @@@@@@@@@@@@@@@@@@@@\n");
        printf("\n           ENTER EMPLOYEE ID : ");
        scanf("%s", emid);
        fprintf(fp1, "%s", emid);

        printf("\n           ENTER EMPLOYEE NAME : ");
        scanf(" %[^\n]", emname);
        fprintf(fp1, " %s", emname);

        printf("\n           ENTER EMPLOYEE DESIGNATION : ");
        scanf(" %[^\n]", emdes);
        fprintf(fp1, " %s", emdes);

        printf("\n           ENTER EMPLOYEE DEPARTMENT : ");
        scanf(" %[^\n]", emdepart);
        fprintf(fp1, " %s", emdepart);

        printf("\n           ENTER EMPLOYEE SALARRY: ");
        scanf(" %[^\n]", emsallary);
        fprintf(fp1, " %s", emsallary);

        printf("\n           ENTER EMPLOYEE ADDRESS : ");
        scanf(" %[^\n]", emaddress);
        fprintf(fp1, " %s", emaddress);

        printf("\n           ENTER EMPLOYEE CONTACT : ");
        scanf(" %[^\n]", emcont);
        fprintf(fp1, " %s", emcont);

        printf("\n           ENTER EMPLOYEE BLOOD GROUP : ");
        scanf("%s",emblg);
        fprintf(fp1, " %s", emblg);
        fclose(fp1);

        printf("\n           @@@@@@@@@@@@@@@@@@ ADD NEW EMPLOYEE DATA INSERTED SUCCESSFULLY @@@@@@@@@@@@@@@@@@\n");

        printf("\n     DO YOU ADD ANOTHER EMPLOYEE?                       ENTER 'y/n' ***->>");
        scanf("%c%c", &ch, &c);

        if(c == 'y'){
            system("cls");
            add_another();
        }
        else{
            system("cls");
            mainmenu();
        }
    }
    else{
        mainmenu();
    }

}

///for show all employee data
void show(){
    int i;
    system("cls");

    while(1){

        char emid[40];
        char emname[40];
        char emdes[40];
        char emaddress[60];
        char emdepart[40];
        char emsallary[20];
        char emcont[40];
        char emblg[10];
        FILE *fp;
        fp = fopen("Alldata.txt", "r");
        printf("\n                      *** YOU ARE GOING TO DISPLAY ALL EMPLOYEE DATA ***\n");

        while(fscanf(fp,"%s%s%s%s%s%s%s%s", emid, emname, emdes, emaddress, emdepart, emsallary, emcont, emblg) != EOF) {

            printf("\n            EMPLOYEE ID : %s\n", emid);
            printf("            EMPLOYEE NAME : %s\n", emname);
            printf("            EMPLOYEE DESIGNATION : %s\n", emdes);
            printf("            EMPLOYEE SALARRY : %s\n", emsallary);
            printf("            EMPLOYEE DEPARTMENT : %s\n", emdepart);
            printf("            EMPLOYEE ADDRESS : %s\n", emaddress);
            printf("            EMPLOYEE CONTACT : %s\n", emcont);
            printf("            EMPLOYEE BLOOD GROUP : %s\n", emblg);
        }
        printf("\n                      *** SUCCESSFULLY DISPLAY ALL EMPLOYEE DATA ***\n");
        fclose(fp);

        printf("Enter '0' for back : ");
        scanf("%d", &i);
        if(i == 0 || i < 100){
            system("cls");
            mainmenu();
            break;
        }
    }
}

///for display single employee data from search id
void dis() {
    int i;
    while(1){
                printf("\n            EMPLOYEE ID : %s\n", semid);
                printf("            EMPLOYEE NAME : %s\n", semname);
                printf("            EMPLOYEE DESIGNATION : %s\n", semdes);
                printf("            EMPLOYEE SALARRY : %s\n", semsallary);
                printf("            EMPLOYEE DEPARTMENT : %s\n", semdepart);
                printf("            EMPLOYEE ADDRESS : %s\n", semaddress);
                printf("            EMPLOYEE CONTACT : %s\n", semcont);
                printf("            EMPLOYEE BLOOD GROUP : %s\n", semblg);
                printf("\n                      *** SUCCESSFULLY DISPLAY SEARCH EMPLOYEE DATA ***\n");
        printf("\nEnter '0' for back : ");
        scanf("%d", &i);
        if(i == 0 || i < 100){
            system("cls");
            mainmenu();
            break;
        }
    }
}


///search by id
void search_em(FILE *dtf, char aid[]) {

    int dres,i=0,n;

    while(fscanf(dtf,"%s %s %s %s %s %s %s %s\n",semid, semname,semdes, semdepart, semsallary,  semaddress, semcont, semblg)!=EOF){
       dres = strcmp(aid, semid);
       if(dres == 0){
            dis();
            i = 1;
       }
    }
    fclose(dtf);

    if(i == 0){
        while(1){
        printf("                     ***--->> No record is Available <<---*** \n");

        printf("Enter '0' for back: ");
        scanf("%d", &n);
        if(n == 0 || n < 0){
            system("cls");
            mainmenu();
            break;
        }
        }
    }


}

///this function also for help search
void display_did(char did[]){
    FILE *dtf;
    dtf = fopen("Alldata.txt","r");

    if(dtf == NULL)
       {
          printf("Error!");
          exit(1);
       }
    search_em(dtf,did);
}

///Edit employee all data by search employee id
void edit(){
    char emid[40];
    char emname[40];
    char emdes[40];
    char emdepart[40];
    char emsallary[20];
    char emaddress[60];
    char emcont[40];
    char emblg[10];


    FILE *fp;
    int del,ress,i;
    char demid[40];

    system("cls");

    printf("\n           >>>>>>>>>>>>>>>>>>>> YOU ARE GOING TO EDIT EMPLOYEE DATA <<<<<<<<<<<<<<<<<<<\n");
    printf("                    PLEASE WRITE THE EMPLOYEE ID FOR EDIT EMPLOYEE : ");
    scanf("%s",&demid);
    FILE *fp3,*fp4;
    fp3 = fopen("Alldata.txt","r");
    fp4 = fopen("Alltemp.txt","w");

    while(fscanf(fp3,"%s %s %s %s %s %s %s %s\n",emid, emname,emdes, emdepart, emsallary,  emaddress, emcont, emblg)!=EOF){
        ress = strcmp(demid,emid);
           if(ress == 0){
                continue;
           }

            fprintf(fp4,"%s %s %s %s %s %s %s %s\n",emid, emname,emdes, emdepart, emsallary,  emaddress, emcont, emblg);

            }

                fclose(fp3);
                fclose(fp4);
                remove("Alldata.txt");
                rename("Alltemp.txt","Alldata.txt");


                fp = fopen("Alldata.txt", "a");

                printf("\n           ENTER EMPLOYEE ID : ");
                scanf("%s", emid);
                fprintf(fp, "\n%s", emid);

                printf("\n           ENTER EMPLOYEE NAME : ");
                scanf(" %[^\n]", emname);
                fprintf(fp, " %s", emname);

                printf("\n           ENTER EMPLOYEE DESIGNATION : ");
                scanf(" %[^\n]", emdes);
                fprintf(fp, " %s", emdes);

                printf("\n           ENTER EMPLOYEE DEPARTMENT : ");
                scanf(" %[^\n]", emdepart);
                fprintf(fp, " %s", emdepart);

                printf("\n           ENTER EMPLOYEE SALARRY: ");
                scanf(" %[^\n]", emsallary);
                fprintf(fp, " %s", emsallary);

                printf("\n           ENTER EMPLOYEE ADDRESS : ");
                scanf(" %[^\n]", emaddress);
                fprintf(fp, " %s", emaddress);

                printf("\n           ENTER EMPLOYEE CONTACT : ");
                scanf(" %[^\n]", emcont);
                fprintf(fp, " %s", emcont);

                printf("\n           ENTER EMPLOYEE BLOOD GROUP : ");
                scanf("%s",emblg);
                fprintf(fp, " %s", emblg);

                fclose(fp);

                printf("\n           >>>>>>>>>>>>>>>>>>>> EMPLOYEE DATA EDITED SUCCESSFULLY <<<<<<<<<<<<<<<<<<<\n");

                printf("Enter '0' for back : ");
                    scanf("%d", &i);
                    if(i == 0 || i < 100){
                        system("cls");
                        mainmenu();
                    }

}


///delete employee by id
void delet()
{
    int del,ress,i, j;
    char demid[40];
    char emid[40];
    char emname[40];
    char emdes[40];
    char emdepart[40];
    char emsallary[20];
    char emaddress[60];
    char emcont[40];
    char emblg[10];

    system("cls");

    printf("\n           >>>>>>>>>>>>>>>>>>>> YOU ARE GOING TO DELETE EMPLOYEE DATA <<<<<<<<<<<<<<<<<<<\n");
    printf("                    PLEASE WRITE THE EMPLOYEE ID FOR DELETE EMPLOYEE \n");
    scanf("%s",&demid);
    FILE *fp3,*fp4;
    fp3 = fopen("Alldata.txt","r");
    fp4 = fopen("Alltemp.txt","w");
    j = 0;
    while(fscanf(fp3,"%s %s %s %s %s %s %s %s\n",emid, emname,emdes, emdepart, emsallary,  emaddress, emcont, emblg)!=EOF){
        ress = strcmp(demid,emid);
           if(ress == 0){
                j = 1;
                continue;
           }

            fprintf(fp4,"%s %s %s %s %s %s %s %s\n",emid, emname,emdes, emdepart, emsallary,  emaddress, emcont, emblg);


            }
            if(j == 1){
                    printf("\n           >>>>>>>>>>>>>>>>>>>> EMPLOYEE DATA DELETED SUCCESSFULLY <<<<<<<<<<<<<<<<<<<\n");
            }
            else {
                printf("\n           >>>>>>>>>>>>>>>>>>>> EMPLOYEE ID NOT FOUND FOR DELETE. <<<<<<<<<<<<<<<<<<<\n");
            }
                    fclose(fp3);
                    fclose(fp4);
                    remove("Alldata.txt");
                    rename("Alltemp.txt","Alldata.txt");

                    printf("Enter '0' for back : ");
                    scanf("%d", &i);
                    if(i == 0 || i < 100){
                        system("cls");
                        mainmenu();
                    }

           }


///this is design function for main menu
void design()
{


    printf("                  .--------------.     .--------------.     .--------------.   \n");
    printf("                | |  _________   | | | | ____    ____ | | | |    _______   | | \n");
    printf("                | | |_   ___  |  | | | ||_   \\  /   _|| | | |   /  ___  |  | | \n");
    printf("                | |   | |_  \\_|  | | | |  |   \\/   |  | | | |  |  (__ \\_|  | | \n");
    printf("                | |   |  _|  _   | | | |  | |\\  /| |  | | | |   '.___`-.   | | \n");
    printf("                | |  _| |___/ |  | | | | _| |_\\/_| |_ | | | |  |`\\____)  | | | \n");
    printf("                | | |_________|  | | | ||_____||_____|| | | |  |_______.'  | | \n");
    printf("                | |              | | | |              | | | |              | | \n");
    printf("                  '--------------'     '--------------'     '--------------'   \n");

}

///here is the main function
int main()
{
    mainmenu();

    return 0;
}
