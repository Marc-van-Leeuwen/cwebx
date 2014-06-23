#define left_margin 1
#define read_mode "r"
/*1:*/
#line 7 "compare.w"
typedef char bool;

/*:1*//*2:*/
#line 14 "compare.w"

/*5:*/
#line 62 "compare.w"

void the_file(bool is_first)
{printf("The %s file ",is_first?"first":"second");}

/*:5*//*7:*/
#line 100 "compare.w"

void open_file(FILE**f,char*prompt,char*name)
{char buf[80];
if(name==NULL||(*f= fopen(name,read_mode))==NULL)
do{printf("%s: ",prompt);fflush(stdout);scanf("%79s",buf);}
while((*f= fopen(buf,read_mode))==NULL);
}

/*:7*/
#line 15 "compare.w"

int main(int n,char**arg)
{FILE*f1,*f2;
int c1,c2,col= left_margin;long line= 1;
/*6:*/
#line 75 "compare.w"

--n;++arg;
if(n==0)
{
open_file(&f1,"First file to compare",NULL);
open_file(&f2,"Second file to compare",NULL);
}
else if(n==1)
{f1= stdin;
if((f2= fopen(*arg,read_mode))==NULL)
{printf("Could not open file %s.\n",*arg);exit(1);}
}
else if(n==2)
{open_file(&f1,"Give another first file",*arg++);
open_file(&f2,"Give another second file",*arg);
}
else
{printf("No more than two command line arguments are allowed.\n");
exit(1);
}

/*:6*/
#line 22 "compare.w"

/*3:*/
#line 35 "compare.w"

while((c1= getc(f1))==(c2= getc(f2))&&c1!=EOF)
if(c1=='\n'){++line;col= left_margin;}else++col;

/*:3*/
#line 24 "compare.w"

/*4:*/
#line 42 "compare.w"

if(c1==c2)printf("Files match.\n");
else
{printf("Files differ.\n");
if(c1==EOF||c2==EOF)
{
the_file(c1==EOF);
printf("is contained in the other as initial segment.\n");
}
else if(c1=='\n'||c2=='\n')
{
the_file(c1=='\n');
printf("has a shorter line number %ld than the other.\n",line);
}
else printf("First difference at line %ld, column %d.\n",line,col);
}

/*:4*/
#line 25 "compare.w"

return 0;
}

/*:2*/
