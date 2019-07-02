#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void accn();
void acce();
void menu();
void reward();
void wallet();
void trending();
void movies();
void sports();
void plays();
void music();
void fests();
void exibhition();
struct username
{
    char name[50];
    int pin[8];
    long int piin,mno;
    float w;
}signup;
void main()
{
    int i;
    system("cls");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* *                                                                       * *\n");
    printf("* *                               Welcome                                 * *\n");
    printf("* *                                 to                                    * *\n");
    printf("* *                            Book My Show!                              * *\n");
    printf("* *                                                                       * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n");
    do
    {
    printf("{1}New User?                  {2}Existing User?                     {3}Exit\n\n");
    printf("Enter Your choice ");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
            accn();
            _getch();
            break;
        case 2:
            acce();
             _getch();
              break;
        case 3:
           printf("Thank You...For Your Visit!!!");
           break;
    }
    }while(i!=3);
}
   void accn()//all the data will be added using structures
   {
       int i;
       FILE *ptr;
       ptr=fopen("F:/hsc/DK.bin","wb");
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
         printf("Enter a valid mobile number ");
         scanf("%ld",&signup.mno);
       }while(signup.mno>9999999999&&signup.mno<1000000000);
       printf("Create your pin (Eight digit pin required!)\n");
        scanf("%ld",&signup.piin);
       fwrite(&signup,sizeof(struct username),1,ptr);
       fclose(ptr);
       printf("Account Created");
       main();
    }
   void acce()
   {
       int i=0,j=0,pass[8];
       char n[50],ch;
       FILE *ptr;
         ptr=fopen("F:/hsc/DK.bin","rb");
         printf("Enter your username\n");
         scanf("%s",&n);
         fread(&signup,sizeof(struct username),1,ptr);
         if(stricmp(signup.name,n)==0)//error pending
         {
             printf("Enter password\n");//big error
             do//screen blank when asks for password
             {
               ch=_getch();
               printf("*");
               fscanf(ptr,"%ld",&signup.piin);
               signup.pin[i]=signup.piin%10;
               signup.piin=signup.piin/10;
               pass[7-i]=signup.pin[i];
               i++;
             }while(ch!=13);
                while(pass[7-j]==signup.pin[j])
                    j++;
                if(j==9)
                {
                    printf("\n{1}Menu                      {2}Rewards Section                      {3}Wallet\n\n");
                    printf("Enter your choice..\n\n");
                    scanf("%d",&i);
                    switch(i)
                       {
                          case 1 :menu();
                          case 2 :reward();
                          case 3 :wallet();
                       }
                }

        else
            {
                printf("\nIncorrect username or password\n\n");

            }
         }
    fclose(ptr);
   }
   void menu()
   {
       int ch;
         printf("**********************************__Welcome__**********************************\n\n");
         do
        {
         printf("{1}Trending      {2}Movies      {3}Sports      {4}Plays       {5}Music Concerts      {6}Fests      {7}Exibhition      {8}Wallet      {9}Log Out..\n\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1 :trending();
             case 2 :movies();
             case 3 :sports();
             case 4 :plays();
             case 5 :music();
             case 6 :fests();
             case 7 :exibhition();
             case 8 :wallet();
             case 9 :printf("Logging Out.......\n\n");
         }
        }while(ch!=9);


   }
   void reward()
   {
         printf("*************************__Welcome to Reward section__*************************\n");
   }
   void wallet()
   {
         struct username money;
         FILE *ptr;
         char reply;
         float amt;
         long acc;
         int b,cvv;
         ptr = fopen("F:/hsc/DK.bin","rb");
         fread(&money,sizeof(struct username),1,ptr);
         printf("Your wallet amount has %d/-\n\n",money.w);
         printf("Do you want to add money to your wallet?\n");
         scanf("%c",&reply);
         if(reply=='y')
         {
             printf("Choose your bank\n\n");
             printf("1.State Bnak of India       2.HDFC      3.ICICI     4.Yes bank");
             scanf("%d",&b);
             printf("Enter account number\n");
             scanf("%ld",&acc);
             printf("Enter cvv\n");
             scanf("%d",&cvv);
             printf("Enter the amount you want to add: ");
             scanf("%f",&amt);
             money.w+=amt;
         }
         fclose(ptr);
         main();
   }
  void trending()
   {

   }
  void movies()
   {
       //FILE *ptr;
       //ptr = fopen("C:/hardik/mov.bin","ab");
       //fwrite();
       int m[16][21][2],ti[336][16][21];
       int s,i,j,a=1,r,c,k;
       printf("");
       printf("");
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
              else if(m[r][c][0]==m[r][c][1])
              {
                  printf("Invalid Input!!\n");
                  printf("Enter Seats Again");
                  main();
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
       main();
        }
        system("cls");
        printf("You have booked the following seats!\n\n");
        for(i=0;i<16;i++)
        {
            for(j=0;j<21;j++)
            printf("%5d-%d",m[i][j][0],m[i][j][1]);
            printf("\n");
        }
        pay();

   }
  void sports()
   {

   }
   void fests()
   {

   }
   void music()
   {

   }
   void exibhition()
   {

   }
  void plays()
  {

  }
  void pay()
  {

      FILE *ptr;
      struct username p;
      float amt;
      ptr = fopen("F:/hsc/DK.bin","rb");
      fread(&p,sizeof(struct username),1,ptr);
      printf("Enter amount\n");
      scanf("%f",&amt);
      p.w = p.w-amt;
      printf("Transaction was successful\n");
      printf("Your current balance %f",p.w);
      fclose(ptr);
  }
