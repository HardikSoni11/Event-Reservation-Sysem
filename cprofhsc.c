#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void accn();
void acce();
void menu();
void booking(char*);
void file(char*);
void adminlogin();
void homepage();
void hall(int);
void pay(float);
struct username
{
    char name[50];
    char piin[16];
    long mno;
    float w;
};
struct lists
{
    int sno;
    char showname[200];
    float price;
};
typedef struct lists list;
typedef struct username user;
void main()
{
    system("cls");
    system("COLOR 8F");
    int ans;
    printf("(1)Administrator                                            (2)User                                         (3)Exit\n\n");
    scanf("%d",&ans);
    if(ans==1)
        adminlogin();
    else if(ans==2)
        homepage();
    else if(ans==3)
        printf("EXITING...");
    else
        {
            printf("Enter valid option");
            delay(3000);
            main();
        }
}
void adminlogin()
{
    char pass[16]="password",p[15];
    int i=0;
    char ch;
    printf("Enter password\n");
      do
        {
            ch=_getch();
            printf("*");
            p[i++]=ch;
        }while(ch!=13);
      p[i-1]='\0';
    if(strcmpi(pass,p)==0)
    {

    FILE *ptr;
     do
        {
         printf("Choose the file you want to edit\n");
         printf("{1}Trending      {2}Movies      {3}Sports      {4}Plays       {5}Music Concerts      {6}Fests      {7}Exibhition       {8}Log Out..\n\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :file("trending");
                     break;
             case 2 :file("movie");
                     break;
             case 3 :file("sport");
                     break;
             case 4 :file("play");
                     break;
             case 5 :file("concert");
                     break;
             case 6 :file("fest");
                     break;
             case 7 :file("exhibition");
                     break;
             case 8 :printf("Logging Out.......\n\n");
         }
        }while(ch!=8);
    }
    else
    {
        printf("Incorrect password");
        delay(3000);
        adminlogin();
    }
}
void file(char type[])
{   FILE *ptr;
    char str[50]="G:/hsc/";
    strcat(str,type);
    strcat(str,".bin");
    ptr=fopen(str,"wb");
    if(ptr==NULL)
    {
      printf("ERROR");
      exit(1);
    }
    char reply;
    list tre;
    printf("Please store the %s shows \n",type);
    do
    {
        printf("Enter serial number\n");
        scanf("%d",&tre.sno);
        printf("Enter name of the show\n");
        _getch();
        scanf("%s",tre.showname);
        printf("Enter the price\n");
        scanf("%f",&tre.price);
        fwrite(&tre,sizeof(list),1,ptr);
        fflush(stdin);
        printf("Do you want to enter more?(y/n)\n");
        scanf("%c",&reply);
    }while(reply=='y');
  fclose(ptr);
}
void homepage()
{
    system("cls");
    system("COLOR F1");
    int i;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* *                                                                       * *\n");
    printf("* *                               Welcome                                 * *\n");
    printf("* *                                 to                                    * *\n");
    printf("* *                             ShowBuzzz!!                               * *\n");
    printf("* *                                                                       * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n");
    do
    {
     printf("{1}SignUp                  {2}LogIn                     {3}Exit\n\n");
     printf("Enter Your choice ");
     scanf("%d",&i);
     switch(i)
      {
        case 1:
            accn();
            break;
        case 2:
            acce();
              break;
        case 3:
           printf("Thank You...For Your Visit!!!\n\n\n");system("cls");
      }
    }while(i!=3);
}
   void accn()
   {
       system("cls");
       user signup;
       int i,cvv,b;
       float amt;
       long acc;
       FILE *ptr;
       ptr=fopen("G:/hsc/pro.bin","ab");
       if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
       printf("                 Experience a modern way of Booking with Us!              \n\n\n");
       printf("                   Let's Start from creating your account                 \n");
       printf("Enter a username \n");
       scanf("%s",signup.name);
       printf("\n");
       do
       {
         system("cls");
         printf("Enter a valid mobile number ");
         scanf("%ld",&signup.mno);
       }while(signup.mno>9999999999||signup.mno<1000000000);
       do
       {
         system("cls");
         printf("Create your password (max length - 15 characters)\n");
         scanf("%s",signup.piin);
       }while(strlen(signup.piin)>15);
        printf("Add money to your wallet\n");
        printf("Enter your bank details\n");
         printf("Choose your bank\n\n");
             printf("1.State Bank of India       2.HDFC      3.ICICI     4.Yes bank\n");
             scanf("%d",&b);
             printf("Enter account number\n");
             scanf("%ld",&acc);
             printf("Enter cvv\n");
             scanf("%d",&cvv);
             printf("Enter the amount you want to add: ");
             scanf("%f",&amt);
             signup.w = 0;
             signup.w+=amt;
       fwrite(&signup,sizeof(struct username),1,ptr);
       fclose(ptr);
       printf("Account Created\n");
       delay(3000);
       menu();
    }
   void acce()
   {
       system("cls");
       system("COLOR 8F");
       user signup, s;
       int i=0,j=0,found=0;
       char n[50],l,ch,pass[16],pin[16];
       FILE *ptr;
         ptr=fopen("G:/hsc/pro.bin","rb");
       if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
         printf("Enter your username\n");
         scanf("%s",n);
         while(!found&&fread(&s,sizeof(user),1,ptr))
           if(strcmpi(n,s.name)==0)
             found++;
         if(found)
         {
             printf("Enter password\n");
             do
             {
               ch=_getch();
               printf("*");
               pass[i++]=ch;
             }while(ch!=13);
             pass[i-1]='\0';
                if(stricmp(pass,s.piin)==0)
                {
                    system("cls");
                    system("COLOR 8F");
                    printf("");
                    printf("");
                    printf("");
                    printf("\n{1}Menu                                                              {2}Log Out\n\n");
                    printf("Enter your choice..\n\n");
                    scanf("%d",&i);
                    switch(i)
                       {
                          case 1 :system("cls");menu();break;
                          case 2 :system("cls");
                                  printf("Logging out.....\n");
                                  delay(5000);
                                  homepage();
                       }
                }

               else
                 {
                    system("COLOR C");
                    printf("\nIncorrect password\n\n");

                }
         }
         else
           {
               printf("Incorrect user name");
               delay(3000);
               acce();
           }
    fclose(ptr);
   }
   void menu()
   {
       system("cls");
       system("COLOR 8F");
       int ch;
         printf("**********************************__Welcome__**********************************\n\n");
         do
        {
         printf("{1}Trending      {2}Movies      {3}Sports      {4}Plays       {5}Music Concerts      {6}Fests      {7}Exibhition          {8}Log Out..\n\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :booking("trending");break;
             case 2 :booking("movie");break;
             case 3 :booking("sport");break;
             case 4 :booking("play");break;
             case 5 :booking("concert");break;
             case 6 :booking("fest");break;
             case 7 :booking("exibhition");break;
            // case 8 :wallet();break;
             case 8 :printf("Logging Out.......\n\n");
         }
        }while(ch!=8);


   }
  void booking(char type[])
   {
      system("cls");
      system("COLOR 0C");
      FILE *ptr;
      char str[50]="G:/hsc/";
      strcat(str,type);
      strcat(str,".bin");
      ptr=fopen(str,"rb");
      int a;
      float pri;
      list tre;
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
       rewind(ptr);
      while(!feof(ptr))
      {
          fread(&tre,sizeof(list),1,ptr);
          printf("%d. ",tre.sno);
          printf("%s ",tre.showname);
          printf("%5f\n",tre.price);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      printf("Enter the amount\n");
      scanf("%f",&pri);
      fclose(ptr);
      hall(pri);
   }
  void hall(int pri)
   {
       system("cls");
       int m[16][21][2];
       int s,i,j,a=1,r,c,k,t,d;
       printf("|_________________________________________________________________________________________________________________________________________________________________|\n");
       printf("                              |                                                                                                      |                             \n");
       printf("                              |                                           Your Screen Here !                                         |                             \n");
       printf("                              |______________________________________________________________________________________________________|                             \n\n\n\n\n");
       for(i=0;i<16;i++)//screen here sajawat pending!!
           for(j=0;j<21;j++)
            {
              m[i][j][0]=i;
              m[i][j][1]=j;
            }
       for(i=0;i<16;i++)
        {
            for(j=0;j<21;j++)
            printf("%5d-%d",m[i][j][0],m[i][j][1]);
            printf("\n");
        }
       printf("|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|\n\n");
       printf("\n");
       printf("Enter no. of seats\n");
       scanf("%d",&s);
       printf("\n");
       if(s<=336&&s>0)
        {
           printf("select your seat numbers\n");
           for(k=1;k<=s;k++)
            {
              scanf("%d-%d",&r,&c);
               if(r<16&&c<21)
              {
                  m[r][c][0]=0;
                  m[r][c][1]=0;
              }
              else
              {
                  system("cls");
                  printf("Invalid Seat number!!\n");
                  printf("Enter Seat Again\n");
                  main();
              }
            }
        }
       else
        {
          system("cls");
          printf("Enter Valid number of seats!\n");
          delay(2001);
          hall(pri);
        }
        system("cls");
        printf("You have booked the following seats!\n\n\n");
        for(i=0;i<16;i++)
        {
            for(j=0;j<21;j++)
            printf("%5d-%d",m[i][j][0],m[i][j][1]);
            printf("\n");
        }
        printf("\n\n");
        printf("                           ------------It's Pay Time------------                           \n\n");
        printf("You selected %d seats\n",s);
        t = pri*s;
        printf("Your Total = %d\n",t);
        printf("Complete Your Payment\n\n");
        pay(t);
        system("cls");
   }
  void pay(float amt)
  {
      FILE *ptr;
      user p;
      ptr = fopen("G:/hsc/pro.bin","rb");
      fread(&p,sizeof(struct username),1,ptr);
      if(p.w<amt)
      {
          printf("Not enough balance\n");
          printf("Redirecting you to menu\n");
          delay(5000);
          fclose(ptr);
          menu();
      }
      else
      {
        p.w = p.w-amt;
      printf("Transaction was successful\n");
      printf("Your current balance %f",p.w);
      delay(10000);
      fclose(ptr);
      menu();
      }

  }
