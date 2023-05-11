#include <bits/stdc++.h>
#include <vector>
using namespace std;

// struct for DNA
struct dna{
    string rna;
    string mokamel;
};


class Genome{
    // Define DNA inside class
    dna d;

    public:
    
    //Input DNA
    void dna_set(string _rna, string _mokamel){
        d.rna = _rna;
        d.mokamel = _mokamel;
    }

    //Output RNA
    string rna_get(){
        return d.rna;
    }

    //Output complementary
    string mokamel_get(){
        return d.mokamel;
    }

    //Making DNA using RNA
    void dna_make(string _rna){
        d.rna = _rna;
        d.mokamel = mokamel_giri(_rna);
    }

    // Mokemel har character
    char mokamel(char c){
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

    //Mokamel string
    string mokamel_giri(string a){
        string ans;
        int i=0;
        while (a[i] != '\0'){
            ans += mokamel(a[i]);
            i++;
        }
        return ans;
    }

    //Jahesh koochak
    void jahesh_koochak(char a, char b, int n){
        int i=0;
        while(n){
            if (d.rna[i] == a){
                d.rna[i] = b;
                d.mokamel[i]=mokamel(b);
                n--;
                }
            i++;
        }
        cout<<"############################"<<endl;
        cout<<d.rna<<' '<<d.mokamel<<endl;
        cout<<"############################"<<endl;
    }

    //Jahesh Bozorg
    void jahesh_bozorg(string a, string b){
        d.rna.replace(d.rna.find(a), b.length(), b);
        d.mokamel.replace(d.mokamel.find(mokamel_giri(a)), b.length(), mokamel_giri(b));

        cout<<"############################"<<endl;
        cout<<"Rna : "<<d.rna;
        cout<<"\nComplementery : "<<d.mokamel<<endl;
        cout<<"############################"<<endl;
        
    }

    //Jahesh Makoos
    void jahesh_makoos(string a){
        string aa=a;  reverse(aa.begin(), aa.end());
        d.rna.replace(d.rna.find(a),a.length(),aa);
        d.mokamel.replace(d.mokamel.find(mokamel_giri(a)), a.length(), mokamel_giri(aa));
        cout<<"############################"<<endl;
        cout<<"Rna : "<<d.rna;
        cout<<"\nComplementery : "<<d.mokamel<<endl;
        cout<<"############################"<<endl;
        
    }
        
};

class Cell: private Genome{

    vector<dna> chromosome;
    
    public:

    // Chromosome is valid or not?
    bool chromosome_check(string s1, string s2){
        int ta = 0, gc=0, fault=0;
        for (int i=0 ; i<s1.length() ; i++){
            if ((s1[i]=='A' && s2[i]=='T') || (s1[i]=='T' && s2[i]=='A'))
                ta++;

            if ((s1[i]=='G' && s2[i]=='C') || (s1[i]=='C' && s2[i]=='G'))
                gc++;

            if (s2[i] != mokamel(s1[i]))
                fault++;
        }
        if ((fault>5) || (ta>gc*3))
            return 0;
        else
            return 1;
    }


    //Input Chromosome 
    bool chromosome_add(string s){
        if(!chromosome_check(s,mokamel_giri(s)))
            return 0;
        dna dd;
        dd.rna = s;    dd.mokamel=mokamel_giri(s);
        chromosome.push_back(dd);
        return 1;
    }

    //Output the chromosome
    void chromosome_get(){
        cout<<"############################";
        cout<<"\nChromosomes: \n";
        for (auto &a : chromosome){
                cout<<a.rna<<' '<<a.mokamel<<endl;
        }
        cout<<"############################"<<endl;
    }

    //Jahesh bozorg
    void jahesh_bozorg(string a, int aa, string b, int bb){
        string s1  = chromosome[aa].rna;
        s1.replace(s1.find(a), b.length(), b);
        chromosome[aa].rna = s1;
        chromosome[aa].mokamel = mokamel_giri(s1);
        
        string s2  = chromosome[bb].rna;
        s2.replace(s2.find(b), a.length(), a);
        chromosome[bb].rna = s2;
        chromosome[bb].mokamel = mokamel_giri(s2);
        cout<<"############################";
        cout<<"\nChromosome changed : "<<chromosome[aa].rna<<' '<<chromosome[aa].mokamel;
        cout<<"\nChromosome changed : "<<chromosome[bb].rna<<' '<<chromosome[bb].mokamel<<endl;
        cout<<"############################"<<endl;
    }

    //Jahesh koochak
    void jahesh_koochak(char a, char b, int n, int m){
        int i=0;
        while(n){
            if (chromosome[m].rna[i] == a){
                chromosome[m].rna[i] = b;
                chromosome[m].mokamel[i]=mokamel(b);
                n--;
                }
            i++;
        }
        cout<<"############################"<<endl;
        cout<<chromosome[m].rna<<' '<<chromosome[m].mokamel<<endl;
        cout<<"############################"<<endl;
    }

    //Jahesh makoos
    void jahesh_makoos(string a, int m){
        string aa=a;  reverse(aa.begin(), aa.end());
        chromosome[m].rna.replace(chromosome[m].rna.find(a),a.length(),aa);
        chromosome[m].mokamel.replace(chromosome[m].mokamel.find(mokamel_giri(a)), a.length(), mokamel_giri(aa));

        cout<<"############################"<<endl;
        cout<<"Rna : "<<chromosome[m].rna;
        cout<<"\nComplementery : "<<chromosome[m].mokamel<<endl;
        cout<<"############################"<<endl;
    }

    // check is palindrome or not?
    bool isPalindrome(string str) {
        string str2 = str;
        reverse(str2.begin(), str2.end());
            if (str == str2) {
                return 1;
            }
        return 0;
    }

    //Output palindrome
    void palindromeFounder(int m) {
        cout<<"############################"<<endl<<endl;
        string str = chromosome[m].rna;
        int len = str.length();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j <= len; j++) {
                string sub_str = str.substr(i, j - i);
                if (sub_str.length() > 1){
                    if (isPalindrome(sub_str)) {
                        cout << sub_str << endl;
                    }
                }
            }
        }
        cout<<"############################"<<endl;
    }

    // Output chromosome
    string chromosome_get(int i){
        return chromosome[i].rna;
    }

    // How many chromosome
    int chromosome_andaze(){
        return chromosome.size();
    }

};
