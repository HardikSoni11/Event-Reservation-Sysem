#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void accn();
void acce();
void menu();
void search();
void wallet();
void trending();
void movies();
void sports();
void plays();
void music();
void fests();
void exibhition();
void adminlogin();
void homepage();
void hall();
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
    printf("___________________________________________________Its ShowBuzz____________________________________________________\n");
    printf("___________________________________________________________________________________________________________________\n\n");
    printf("(1)Administrator                                            (2)User                                         (3)Exit\n");
    printf("___________________________________________________________________________________________________________________\n");
    scanf("%d",&ans);
    printf("\n\n");
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
    char pass[16]="password",p[15],ch;
    int i=0;
    printf("Enter password\n");
      do
        {
            ch =_getch();
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
         printf("{1}Trending      {2}Movies      {3}Sports      {4}Plays       {5}Music Concerts      {6}Fests      {7}Exibhition      {8}Wallet      {9}Log Out..\n\n");
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
             case 8 :wallet();break;
             case 9 :printf("Logging Out.......\n\n");
         }
        }while(ch!=9);
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
    char str[50]="c:/codeblocks/";
    strcat(str,type);
    strcat(str,".bin");
    ptr=fopen(str,"ab");
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
        scanf("%d",&tre.sno);
        printf("Enter name of the show\n");
        gets(tre.showname);
        printf("Enter the price");
        scanf("&f",&tre.price);
        fwrite(&tre,sizeof(list),1,ptr);
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
   void accn()//all the data will be added using structures
   {
       system("cls");
       user signup;
       int i;
       FILE *ptr;
       ptr=fopen("G:/hsc/pro.bin","ab");
       if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
       printf("                 Experience a modern way of Booking with Us!              \n\n\n");
       printf("                   Let's Start from creating your account                 \n");
       system("cls");
       printf("Note - Your Information is highly secure.It will not be shared anywhere.We require your information only for verifying purposes.(You will be redirected to login page in 4sec)\n");
       delay(4000);
       system("cls");
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


       fwrite(&signup,sizeof(struct username),1,ptr);
       fclose(ptr);
       printf("Account Created");
       delay(3500);
       menu();//change
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
         if(found)//error pending
         {
             printf("Enter password\n");//big error
             do//screen blank when asks for password
             {
               ch=_getch();
               printf("*");
               pass[i++]=ch;
             }while(ch!=13);
             pass[i-1]='\0';
                if(stricmp(pass,signup.piin)==0)
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
         printf("{1}Trending      {2}Movies      {3}Sports      {4}Plays       {5}Music Concerts      {6}Fests      {7}Exibhition      {8}Wallet      {9}Log Out..\n\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :trending();break;
             case 2 :movies();break;
             case 3 :sports();break;
             case 4 :plays();break;
             case 5 :music();break;
             case 6 :fests();break;
             case 7 :exibhition();break;
             case 8 :wallet();break;
             case 9 :printf("Logging Out.......\n\n");
         }
        }while(ch!=9);


   }

   void wallet()
   {
         user money;
         FILE *ptr;
         char reply;
         float amt;
         long acc;
         int b,cvv;
         ptr = fopen("G:/hsc/pro.bin","rb");
       if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
         fread(&money,sizeof(struct username),1,ptr);
         fflush(stdin);
         _getch();
         printf("Your wallet amount has %d/-\n\n",money.w);
         printf("Do you want to add money to your wallet?(y/n)\n");
         _getch();
         scanf("%c",&reply);
         if(reply=='y')
         {
             printf("Choose your bank\n\n");
             printf("1.State Bank of India       2.HDFC      3.ICICI     4.Yes bank");
             scanf("%d",&b);
             printf("Enter account number\n");
             scanf("%ld",&acc);
             printf("Enter cvv\n");
             scanf("%d",&cvv);
             printf("Enter the amount you want to add: ");
             scanf("%f",&amt);
             money.w+=amt;
         }
         else(reply=='n');
         {
          system("cls");
          menu();
         }
         fclose(ptr);
   }
  void trending()
   {
      system("cls");
      system("COLOR 0C");
      int a;
      float pri;
      FILE *ptr;
      list tre;
      ptr=fopen("c:/codeblocks/trending.bin","rb");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fread(&tre,sizeof(list),1,ptr);
          printf("%d. ",tre.sno);
          printf("%s ",tre.showname);
          printf("%10f\n",tre.price);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      //choose pri on the basis of a(seekg)
      fclose(ptr);
      hall(pri);
   }
  void movies()
   {
      system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/movie.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();

   }

  void sports()
   {
      system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/sport.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();


   }
   void fests()
   {
       /*int a;
       printf("Following fests are being currently held near you!\n");
       printf("{1}.Kreiva 2k17\n");
       printf("{2}.Synapse 2k17\n");
       printf("{3}.Aarabdhi 2k17\n");
       printf("{4}.Exit to menu\n");
       printf("Choose to book tickets\n\n");
       scanf("%d",&a);
       switch(a)
       {
           case 1 : printf("Kreiva 2k17 - 250/-\n");pay();
           case 2 : printf("Synapse 2k17 - 170/-\n");pay();
           case 3 : printf("Aarabdhi 2k17 - 680/-\n");pay();
           case 4 : system("cls");menu();
       }*/
       system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/fest.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();

    }
   void music()
   {
     system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/concert.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();

   }
   void exibhition()
   {
      system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/exhibition.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();

   }
  void plays()
  {
      system("cls");
      system("COLOR 0C");
      int a;
      FILE *ptr;
      char tre[200];
      ptr=fopen("c:/codeblocks/play.txt","r");
             if(ptr==NULL)
       {
           printf("ERROR");
           exit(1);
       }
      while(!feof(ptr))
      {
          fscanf(ptr,"%s",tre);
          printf("%s ",tre);
      }
      printf("\n\n");
      printf("Choose your show...\n");
      scanf("%d",&a);
      fclose(ptr);
      hall();

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
          movies();
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
        printf("{1}Proceed to pay                                                       {2}Check Wallet\n\n");
        printf("Note: If you choose wallet, You will have to login again,This is for security purposes.\n\n");
        scanf("%d",&d);
        switch(d)
        {
           case 1 : pay();
           case 2 : wallet();

        }
        system("cls");
   }
  void pay()
  {
      FILE *ptr;
      user p;
      float amt;
      ptr = fopen("G:/hsc/pro.bin","rb");
      fread(&p,sizeof(struct username),1,ptr);
      printf("Enter Required amount\n");
      scanf("%f",&amt);
      p.w = p.w-amt;
      printf("Transaction was successful\n");
      printf("Your current balance %f",p.w);
      fclose(ptr);
  }
void search()//for administrator
{
    user s;
    FILE *ptr;
    ptr = fopen("c:/codeblocks/pro.bin","rb");
    char n[50];
    int found=0;
    printf("Enter username\n");
    scanf("%s",n);
    while(!found&&fread(&s,sizeof(user),1,ptr))
        if(strcmpi(n,s.name)==0)
           found++;
    fclose(ptr);
}

