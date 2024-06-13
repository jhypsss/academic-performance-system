#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct student{
    char name[100];
    float WWTotal, PTTotal; // Written Work Total Score, Performance Task Total Score
    float WWHighTotalScore, PTHighTotalScore; //Highest Possible Scores of WW and PT
    float wwPercentageScore, wwWeightedScore, ptPercentageScore, ptWeightedScore; //Percentage Score , Weighted Score
    float iGrade, fGrade; // Initial Grade, Final Grade
    char classremark[255];
}; struct student s;

//Global Declaration
char select; //select var in switch
FILE *fpdata; //file pointer

void datacheck(){
    fpdata = fopen("gradedata.csv", "r");

    if (fpdata == NULL){
        fclose(fpdata);
        fpdata = fopen("gradedata.csv", "w+");
            fprintf(fpdata, "LASTNAME,FIRSTNAME,WW_SCORE,PERCENTAGE_WW,WEIGHTED_WW,PT_SCORE,PERCENTAGE_PT,WEIGHTED_PT,INITIAL_GRADE,FINAL_GRADE,CLASS_REMARK");
        fclose(fpdata);
    }
}

void emptyvar(){ /// Clearing Structured Variables
    if(sizeof(s)!=0){
        char name[100] = "NULL";
        char classremark[255] = "NULL";
        strcpy(s.name, name);
        strcpy(s.classremark, classremark);
        s.WWTotal=0; 
        s.PTTotal=0;
        s.WWHighTotalScore=0;
        s.PTHighTotalScore=0;
        s.wwPercentageScore=0;
        s.wwWeightedScore=0;
        s.ptPercentageScore=0;
        s.ptWeightedScore=0;
        s.iGrade=0;
        s.fGrade=0;
    }
}

void loadscreen(){
    printf("Loading... Please Wait. \n\n");
    printf("LOADING: ");
    for (int i=1; i<=85; i+=2){
        Sleep(10);
        printf(" %c", 219); //219 is a Bar-like character in ASCII code
    }
}

void ComputeGrade(){
    s.wwPercentageScore = (s.WWTotal/s.WWHighTotalScore) * 100; //Percentage Score of WW
    s.wwWeightedScore = s.wwPercentageScore * 0.3; //Weighted Score of WW
    s.ptPercentageScore = (s.PTTotal/s.PTHighTotalScore) * 100; //Percentage Score of PT
    s.ptWeightedScore = s.ptPercentageScore * 0.7; // Weighted Score of PT
    s.iGrade = s.wwWeightedScore + s.ptWeightedScore; // Initial Grade
}

void FinalGrade(){
    if (s.iGrade == 100 )
        s.fGrade = 100;
    else if (s.iGrade >= 98.40 && s.iGrade <= 99.99)
        s.fGrade = 99;
    else if (s.iGrade >= 96.80 && s.iGrade <= 98.39)
        s.fGrade = 98;
    else if (s.iGrade >= 95.20 && s.iGrade <= 96.79)
        s.fGrade = 97;
    else if (s.iGrade >= 93.60 && s.iGrade <= 95.19)
        s.fGrade = 96;
    else if (s.iGrade >= 92.00 && s.iGrade <= 93.59)
        s.fGrade = 95;
    else if (s.iGrade >= 90.40 && s.iGrade <= 91.99)
        s.fGrade = 94;
    else if (s.iGrade >= 88.80 && s.iGrade <= 90.39)
        s.fGrade = 93;
    else if (s.iGrade >= 87.20 && s.iGrade <= 88.79)
        s.fGrade = 92;
    else if (s.iGrade >= 85.60 && s.iGrade <= 87.19)
        s.fGrade = 91;
    else if (s.iGrade >= 84.00 && s.iGrade <= 85.59)
        s.fGrade = 90;
    else if (s.iGrade >= 82.40 && s.iGrade <= 83.99)
        s.fGrade = 89;
    else if (s.iGrade >= 80.80 && s.iGrade <= 82.39)
        s.fGrade = 88;
    else if (s.iGrade >= 79.20 && s.iGrade <= 80.79)
        s.fGrade = 87;
    else if (s.iGrade >= 77.60 && s.iGrade <= 79.19)
        s.fGrade = 86;
    else if (s.iGrade >= 76.00 && s.iGrade <= 77.59)
        s.fGrade = 85;
    else if (s.iGrade >= 74.40 && s.iGrade <= 75.99)
        s.fGrade = 84;
    else if (s.iGrade >= 72.80 && s.iGrade <= 74.39)
        s.fGrade = 83;
    else if (s.iGrade >= 71.20 && s.iGrade <= 72.79)
        s.fGrade = 82;
    else if (s.iGrade >= 69.60 && s.iGrade <= 71.19)
        s.fGrade = 81;
    else if (s.iGrade >= 68.00 && s.iGrade <= 69.59)
        s.fGrade = 80;
    else if (s.iGrade >= 66.40 && s.iGrade <= 67.99)
        s.fGrade = 79;
    else if (s.iGrade >= 64.80 && s.iGrade <= 66.39)
        s.fGrade = 78;
    else if (s.iGrade >= 63.20 && s.iGrade <= 64.79)
        s.fGrade = 77;
    else if (s.iGrade >= 61.60 && s.iGrade <= 63.19)
        s.fGrade = 76;
    else if (s.iGrade >= 60.00 && s.iGrade <= 61.59)
        s.fGrade = 75;
    else if (s.iGrade >= 56.00 && s.iGrade <= 59.99)
        s.fGrade = 74;
    else if (s.iGrade >= 52.00 && s.iGrade <= 55.99)
        s.fGrade = 73;
    else if (s.iGrade >= 48.00 && s.iGrade <= 51.99)
        s.fGrade = 72;
    else if (s.iGrade >= 44.00 && s.iGrade <= 47.99)
        s.fGrade = 71;
    else if (s.iGrade >= 40.00 && s.iGrade <= 43.99)
        s.fGrade = 70;
    else if (s.iGrade >= 36.00 && s.iGrade <= 39.99)
        s.fGrade = 69;
    else if (s.iGrade >= 32.00 && s.iGrade <= 35.99)
        s.fGrade = 68;
    else if (s.iGrade >= 28.00 && s.iGrade <= 31.99)
        s.fGrade = 67;
    else if (s.iGrade >= 24.00 && s.iGrade <= 27.99)
        s.fGrade = 66;
    else if (s.iGrade >= 20.00 && s.iGrade <= 23.99)
        s.fGrade = 65;
    else if (s.iGrade >= 16.00 && s.iGrade <= 19.99)
        s.fGrade = 64;
    else if (s.iGrade >= 12.00 && s.iGrade <= 15.99)
        s.fGrade = 63;
    else if (s.iGrade >= 8.00 && s.iGrade <= 11.99)
        s.fGrade = 62;
    else if (s.iGrade >= 4.00 && s.iGrade <= 7.99)
        s.fGrade = 61;
    else if (s.iGrade >= 0 && s.iGrade <= 3.99)
        s.fGrade = 60;
}

void GradeClass(){
    if (s.fGrade < 75){
        strcpy(s.classremark, "DID NOT MEET EXPECTATIONS");
    }
    else if (s.fGrade >= 75 && s.fGrade < 80){
        strcpy(s.classremark, "FAIRLY SATISFACTORY");
    }
    else if (s.fGrade >= 80 && s.fGrade < 85){
        strcpy(s.classremark, "SATISFACTORY");
    }
    else if (s.fGrade >= 85 && s.fGrade < 90){
        strcpy(s.classremark, "VERY SATISFACTORY");
    }
    else if (s.fGrade >= 90 && s.fGrade <= 100){
        strcpy(s.classremark, "OUTSTANDING");
    }
}

void addrecord(){
    fpdata = fopen("gradedata.csv", "a+");
            printf("NEW RECORD ADDED: \n\n");
            printf("Name of Student: %s\n\n", s.name);
            printf("Written Works Total Score: %.0f/%.0f\n", s.WWTotal, s.WWHighTotalScore);
            printf("\tPercentage Score: %.2f\n", s.wwPercentageScore);
            printf("\tWeighted Score: %.2f\n\n", s.wwWeightedScore);

            printf("Performance Tasks Total Score: %.0f/%.0f\n", s.PTTotal, s.PTHighTotalScore);
            printf("\tPercentage Score: %.2f\n", s.ptPercentageScore);
            printf("\tWeighted Score: %.2f\n", s.ptWeightedScore);

            printf("\nInitial Grade: %.2f\n", s.iGrade);
            printf("Final Grade: %.2f\n", s.fGrade);
            printf("Class Remark: %s", s.classremark);
        fprintf(fpdata, "\n%s,%.0f,%.2f,%.2f,%.0f,%.2f,%.2f,%.2f,%.0f,%s", s.name, s.WWTotal, s.wwPercentageScore, s.wwWeightedScore, s.PTTotal, s.ptPercentageScore, s.ptWeightedScore, s.iGrade, s.fGrade, s.classremark);
    fclose(fpdata);
}

void enterstudentdata(){
    while (1)
    {
        system("cls");
        emptyvar();
        int nWW=0, nPT=0; //number of WW or number of PT

        printf("ENTER NEW STUDENT DATA\n");
        printf("Enter Name: example(Lastname,Firstname)\n");
        printf("Name: ");
        scanf("%s", s.name);

        system("cls");
        printf("\nWRITTEN WORKS\n");
        printf("Name of Student: %s\n", s.name);
        printf("\nEnter Number of Written Works: ");
        float WWscore[nWW], WWHscore[nWW];
        scanf("%d", &nWW);

        for(int i=0; i<nWW; i++){
            printf("\nEnter Highest Possible Score of Written Works #%d: ", i+1);
            scanf("%f", &WWHscore[i]);
            s.WWHighTotalScore = s.WWHighTotalScore + WWHscore[i];

            printf("Enter Your Score of Written Work #%d: ", i+1);
            scanf("%f", &WWscore[i]);
            s.WWTotal = s.WWTotal + WWscore[i];
        }
        printf("\nTotal Written Works Score is: %.0f/%.0f\n", s.WWTotal, s.WWHighTotalScore);
        printf("\nPress any key to continue...");
        getche();

        system("cls");
        printf("\nPERFORMANCE TASKS\n");
        printf("Name of Student: %s\n", s.name);
        printf("\nEnter Number of Perfomance Tasks: ");
        float PTScore[nPT], PTHScore[nPT];
        scanf("%d", &nPT);

        for(int i=0; i<nPT; i++){
            printf("\nEnter Highest Possible Score of Performance Task #%d: ", i+1);
            scanf("%f", &PTHScore[i]);
            s.PTHighTotalScore = s.PTHighTotalScore + PTHScore[i];

            printf("Enter Your Score of Performance Task #%d: ", i+1);
            scanf("%f", &PTScore[i]);
            s.PTTotal = s.PTTotal + PTScore[i];
        }
        printf("\nTotal Performance Task Score is: %.0f/%.0f\n", s.PTTotal, s.PTHighTotalScore);
        printf("\nPress any key to continue...");
        getche();

        //Summary (Asks to Save Record)
        system("cls");
        printf("SUMMARY RECORD\n\n");
        printf("Name of Student: %s\n\n", s.name);
        printf("Written Works Total Score: %.0f/%.0f\n", s.WWTotal, s.WWHighTotalScore);
        printf("Performance Tasks Total Score: %.0f/%.0f\n", s.PTTotal, s.PTHighTotalScore);


        printf("\nAdd this Record?\n");
        printf("[Y]Yes \t\t [N] No\n");
        printf("SELECT: ");
        select = getche();

        if(select == 'N' || select == 'n'){
            emptyvar();
            printf("\n\nReturning to Main Menu\nPress any Key To Continue...\n");
            getche();
            return;
        }else if (select == 'Y' || select == 'y'){
            system("cls");
            datacheck();
            ComputeGrade();
            FinalGrade();
            GradeClass();
            addrecord();
            printf("\n\nPress any key to continue... ");
            getch();
            return;
        }
    }
}

void viewdata(){
    char ch;
    system("cls");
    while(1){
        system("cls");
        fpdata = fopen("gradedata.csv", "r");
        if(fpdata == NULL){
            printf("You Don't Have A Record Yet");
        }else{
            loadscreen();
            system("cls");
            while(!feof(fpdata)){
                ch = fgetc(fpdata);
                printf("%c",ch);
            }
        }
        fclose(fpdata);
        printf("\n\nPress any key to continue... ");
        getche();
        return;
    }
}

void exitprogram(){
    while(1){
        system("cls");
        printf("ARE YOU SURE YOU WANT TO EXIT?\n");
        printf("[Y] YES (Exit Program)\n");
        printf("[N] NO (Go Back To Main Page)\n");
        printf("SELECT: ");
        select = getche();

        if (select == 'Y' || select == 'y'){
            system("cls");
            printf("Thank You.");
            exit(0);
        } else if (select == 'N' || select == 'n'){
            return;
        }
    }
}

void deleteallrecords(){
    while(1){
    system("cls"); 
    printf("Warning...\n"
    "This will delete all your records\n"
    "Are you sure you want to delete all?\n\n"
    "\t[N] No \t [Y] Yes\n\n"
    "Select: ");
    select = getche();

    if(select=='n' || select=='N'){
            return;
        }
        else if(select=='y' || select=='Y'){ //else if Yes, then remove all the data you have
            system("cls");
            loadscreen();
            remove("gradedata.csv");
            printf("\n\nDone !\n\nPress any key to continue... ");
            getche();
            return;
        }
    }
}

int main() {

    while(1) {
        system("cls"); // Clear Screen
        printf("ANALYZING STUDENT ACADEMIC PERFORMANCE\n");
        printf("[1] Enter New Student Data\n");
        printf("[2] View All Data\n");
        printf("[0] Exit Program\n");
        printf("SELECT NO: ");
        select = getche();

        switch(select){
            case '1': enterstudentdata();
            break;
            case '2': viewdata();
            break;
            case '0': exitprogram();
            break;
            case 'X': deleteallrecords();
            break; 
        }
    }

getch();
return 0;
}