#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

bool Convert(const string &ifile,const string &ofile,char word,const string &convert)
{
    vector<char> file;
    char ch;
    FILE *fp=fopen(ifile.data(),"r");
    if(!fp)
    {
        printf("Converted file does not exist!");
        return false;
    }
    char ask[]="whereispassword?";
    int times=0;
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
        if(ch=='w')
        {
            ch=ask[times%16];
            times++;
        }
        file.push_back(ch);
    }
    fclose(fp);

    fp=fopen(ofile.data(),"w");
    if(!fp)
    {
        printf("Cannot create output file!");
        return false;
    }
    for_each(file.begin(),file.end(),[fp](char x){fprintf(fp,"%c",x);});
    fclose(fp);
    return true;
}

int main()
{
    char word;
    string convert,ifile,ofile;
    printf("Convert words to a sentence:\n"
           "\nPlease input the converted word:");
    scanf("%c",&word);
    getchar();
    printf("Convert sentence:");
    getline(cin,convert);

    printf("\nPlease input the converted file name(000 to exit):");
    cin>>ifile;
    while(strcmp(ifile.c_str(),"000")!=0)
    {
        printf("Please input the output file name:");
        cin>>ofile;
        bool success=Convert(ifile,ofile,word,convert);

        if(success)printf("Complete!\n");

        printf("\nPlease input the file name(000 to exit):");
        cin>>ifile;
    }

    return 0;
}
