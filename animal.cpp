#include <bits/stdc++.h>
#include <cstdlib>
#include "Cell.h"
using namespace std;
class Animal;

class Virus{
    string RNA;
    
    public:
    
    //Input Rna
    void rna_set(string RNA){
        this -> RNA = RNA;
    }
    // Most repeated sub-String
    string common (vector <string> rnas){
        string ans;
        if (rnas.size()==1)
            ans = rnas[0];
        else{
            string s=rnas[0];
            int n = rnas.size();
            int n2 = s.length();

            for(int i=0 ; i<n2 ; i++ ){
                for (int j=i+1 ; j<=n2 ; j++){
                    string sub = s.substr(i,j);
                    int k = 1;
                    for ( ; k<n ; k++){
                        if (rnas[k].find(sub)==std::string::npos)
                            break;
                    }
                    if (k==n && ans.length() < sub.length())
                        ans = sub;
                }
            } 
        }

        return ans;
    }

    bool IsDangerous(Animal anim);

};

class Animal : public Cell {

    public:

    //Hamming distance
    double similarityA(string s1, string s2){
        int dif=0;
        for (int i=0 ; i<s1.length() ; i++){
            if (s1[i] != s2[i])
                dif++;
        }
        return dif;
    }

    //Eliya distance
    double similarityB(string s1, string s2) {
        int Tc1=0,Ac1=0,Gc1=0,Cc1=0;
        int Tc2=0,Ac2=0,Gc2=0,Cc2=0;

        for (int i=0 ; i<s1.length() ; i++ ){
            if (s1[i] == 'T')
                Tc1++;
            else if (s1[i] == 'A')
                Ac1++;
            else if (s1[i] == 'G')
                Gc1++;
            else{
                Cc1++;
            }
        }

        for (int i=0 ; i<s2.length() ; i++ ){
            if (s2[i] == 'T')
                Tc2++;
            else if (s2[i] == 'A')
                Ac2++;
            else if (s2[i] == 'G')
                Gc2++;
            else{
                Cc2++;
            }
        }

        int dif = (max(Tc1,Tc2)-min(Tc1,Tc2)) + (max(Cc1,Cc2)-min(Cc1,Cc2)) +
                 (max(Ac1,Ac2)-min(Ac1,Ac2)) + (max(Gc1,Gc2)-min(Gc1,Gc2));

        return dif;
    }
    // output the similarity of two animals
    double operator==(Animal &a2){
        int a=0;
        for (int i=0 ; i<chromosome_andaze() ; i++){
            string s1 = chromosome_get(i);
            string s2 = a2.chromosome_get(i);
            a += 100-100*(min(similarityB(s1,s2),similarityA(s1,s2))/s1.length());
        }
        double sim = a/chromosome_andaze();
        return sim;
    
    }
    // asexual reproduction
    void asexual(Animal &anim3){
        vector <string> daste;
        int n = chromosome_andaze();
        for (int i=0 ; i<n ; i++){
            daste.push_back(chromosome_get(i));
        }
        for (int i=0 ; i<n ; i++){
            daste.push_back(chromosome_get(i));
        }

        int t=0;
        while(t<n){    
            for (int i=0 ; i<2*n ; i++ ){
                int randi = 1+(rand()%2);
                if (randi>1){
                    anim3.chromosome_add(daste[i]);
                    t++;
                }
                if (t==n)
                    break;
            }
            if (t==n)
                    break;
        }
    }
    //sexual reproduction
    Animal operator+(Animal &anim2){
        Animal child;
        int n = anim2.chromosome_andaze();
        while(n--){
            int i=0;
            int randi = 1+(rand()%100);
            if (randi > 35)
                child.chromosome_add(chromosome_get(i));
            else
                child.chromosome_add(anim2.chromosome_get(i));
            i++;
        }
        return child;
    }

    //Kills the animal
    Animal death(){
        cout<<"\nBefarmayid Halva\n";
        Animal dead;
        return dead;
    }

    friend class Virus;
} ;
// complementary char 
char mokamel2(char c){
        if (c=='A')
            return 'T' ;
        else if (c=='T')
            return 'A' ;
        else if (c=='C')
            return 'G' ;
        else if (c=='G')
            return 'C' ;
        else
            return '!';
    }
// complementary string
string mokamel_giri2(string a){
        string ans;
        int i=0;
        while (a[i] != '\0'){
            ans += mokamel2(a[i]);
            i++;
        }
        return ans;
    }
// virus can kill or not
bool Virus::IsDangerous(Animal anim){
        vector <string> rnas;
        for (int i=0; i<anim.chromosome_andaze() ; i++){
            rnas.push_back(anim.chromosome_get(i));
        }
        string s1 = common(rnas);
        string s2 = mokamel_giri2(s1);
        if ((RNA.find(s1) <= RNA.length()) || (RNA.find(s2) <= RNA.length()))
            return 1;
        else
            return 0;
    }
