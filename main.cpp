#include "Cell.h"
#include "Animal.h"

int main(){
    srand((unsigned) time(NULL));

    Genome gen;
    Cell cell;
    string rna;
    char response;
    
    while(true){
    // Main part of the menu
    system("clear");
    cout<<"<<<<<<<<<< Hello :) >>>>>>>>>>\n\n";
    cout<<"What do you wnat to do?\n"<<
           "1- Input a Dna [D] \n"<<
           "2- Input a Rna to make a Dna [R] \n"<<
           "3- Input a Cell by chromosomes [C] \n"<<
           "4- Work with Animals [A] \n"<<
           "5- Exit [E] \n"<<
           ": "; cin>>response;
    
    //1- Input a Dna [D]       
    if (response=='D'){
        string mokamel;
        cout<<endl<<"Rna: ";cin>>rna;
        cout<<endl<<"Complementery: ";cin>>mokamel;
        gen.dna_set(rna,mokamel);

        cout<<"\nRna : "<<gen.rna_get()<<endl;
        cout<<"\nComplementery : "<<gen.mokamel_get()<<endl;

    }
    
    //2- Input a Rna to make a dna [R]
    else if (response == 'R'){
        cout<<endl<<"Rna: ";cin>>rna;
        gen.dna_make(rna);
    
        cout<<"\nRna : "<<gen.rna_get()<<endl;
        cout<<"\nComplementery : "<<gen.mokamel_get()<<endl;

    }
    
    //3- Input a Cell by chromosomes [C]
    else if (response == 'C'){
        int n;
        cout<<"\nHow many Chromosomes do you wnat to make? :";     cin>>n;
        string s;
        
        bool situation = true;
        while(n--){
            cout<<"Input here: ";
            cin>>s;
            situation = cell.chromosome_add(s);
            if (!situation){
                cout<<"\nInvalid Chromosomes !\n";
                n++;
            }
        }

        cell.chromosome_get();
    }
    // 4- Work with Animals [A]
    else if (response == 'A'){
        Animal anim1;
        Animal anim2;
        int a;
        
        // Input the Animal1
        cout<<"\nTell me the number of the chromosomes of the first animal : ";
        cin>>a;
        bool situation = true;
        while(a--){
            string c;
            cout<<"\nchromosome : "; cin>>c;
            situation = anim1.chromosome_add(c);
            if (!situation){
                cout<<"\nInvalid Chromosomes !\n";
                a++;
            }
        }
        anim1.chromosome_get();
        
        // Input the Animal2
        cout<<"\nTell me the number of the chromosomes of the second animal : ";
        cin>>a;
        situation = true;
        while(a--){
            string c;
            cout<<"\nchromosome : "; cin>>c;
            situation = anim2.chromosome_add(c);
            if (!situation){
                cout<<"\nInvalid Chromosomes !\n";
                a++;
            }
        }
        anim2.chromosome_get();

        while(true){
            cout<<"\nWhat do you want to do? [Compare - Asexual - sexual - Death - Virus - 0] : ";
            string answer;      cin>>answer;
            
            // Compare two animals
            if (answer == "Compare"){
                if ((anim1==anim2)>=70)
                    cout<<"\nTwo animals are from a same species with "<<(anim1==anim2)<<" similarity\n";
                else
                    cout<<"\nTwo animals aren`t from a same species with "<<(anim1==anim2)<<" similarity\n";
            }

            // Asexual Reproduction
            else if (answer == "Asexual"){
                while(true){
                    Animal anim3;
                    anim1.asexual(anim3);
                    if ((anim1==anim3)>=70){
                        cout<<"\nAnimal3 made by " << (anim1==anim3) <<" similarity.\n";
                        anim3.chromosome_get();
                        break;
                    }
                }
            }

            // Killing the animal
            else if (answer == "Death"){
                anim1 = anim1.death();
                anim2 = anim2.death();
                cout<<"\nPress any key to back to the menu: ";
                char any_key;   cin>>any_key;
            }

            else if (answer == "sexual"){
                // Number of the chromosomese were odd
                if (anim1.chromosome_andaze()%2==1 || anim2.chromosome_andaze()%2==1)
                    cout<<"\nReproduction unsuccessful.\n";

                // First making anim3 & anim4 by asexual reproduction
                else{
                    Animal anim3,anim4;

                    // Making animal 3  
                    while(true){
                        Animal test1;
                        anim1.asexual(test1);
                        if ((anim1==test1)>=70){
                            anim3 = test1;
                            break;
                        }
                    }

                    // Making animal 4
                    while(true){
                        Animal test1;
                        anim1.asexual(test1);
                        if ((anim1==test1)>=70){
                            anim4 = test1;
                            break;
                        }
                    }
                    
                    // Sexual reproduction
                    while(true){
                        Animal anim5 = anim3+anim4;
                        if ((anim5==anim1)>=70){
                            cout<<"\nAnimal3 made with " << (anim5==anim1) <<" similarity\n";
                            anim5.chromosome_get();
                            break;
                        }
                    }
                }
            }
            
            //Virus section
            else if (answer == "Virus"){
                Virus virus;
                string VRNA;
                cout<<"\nInput the RNA of the Virus : \n";      cin>>VRNA;
                
                // Input Virus RNA
                virus.rna_set(VRNA);
                cout<<"\nWhich animal do you want to attack on with the virus? [1 - 2] : ";
                char a;     cin>>a;
                
                // Attack to animal1
                if (a == '1'){

                    // IsDnagerous == 1
                    if (virus.IsDangerous(anim1)){
                        anim1 = anim1.death();
                        cout<<"\nVirus killed the animal1.\n";
                    }
                    // IsDnagerous == 0
                    else{
                        cout<<"Virus couldn`t kill the animal1.\n";
                    }
                }

                // Attack to animal2
                else if(a=='2'){
                    
                    // IsDnagerous == 1
                    if (virus.IsDangerous(anim2)){
                        anim2 = anim2.death();
                        cout<<"\nVirus killed the animal2.\n";
                    }
                    // IsDnagerous == 0
                    else
                        cout<<"Virus couldn`t kill the animal2.\n";    
                }

                // Invalid input
                else{
                    cout<<"\nInvalid input\n";
                }

            }
            
            // close this section
            else if(answer == "0"){
                break;
            }

            // Invalid Input
            else{
                cout<<"\nInva888lid input\n";
            }

        }

    }

    string task;
        // DNA section
        if (response=='D' || response == 'R'){    
            while(true){
            cout<<"\nWhat do you want to do? [SMutation - BMutation - Reversion - 0] : ";
            cin>> task;
            
            // Small mutation
            if (task == "SMutation"){
                char a,b;   int n;
                cout<<"\nTell me what do you want to change? [A C 3] {it means replace 3 A with C} : ";
                cin>>a>>b>>n;
                gen.jahesh_koochak(a,b,n+1);
            }

            // Big mutation
            else if (task == "BMutation"){
                string a,b;
                cout<<"\nTell me what do you want to change? [A B] {it means replace A with B} : ";
                cin>>a>>b;
                gen.jahesh_bozorg(a,b);
            }
            
            // Reversion
            else if (task == "Reversion"){
                string a;
                cout<<"\nTell me what do you want to change? [A] {it reverses the A} : ";
                cin>>a;
                gen.jahesh_makoos(a);
            }

            // Close this section
            else if (task == "0"){
                break;
            }

            //Invalid input
            else{
                cout<<"Invalid input";
            }
        }
    }
        // Chromosome section
        else if(response=='C'){
            while(true){
            cout<<"\nWhat do you want to do? [SMutation - BMutation - Reversion - Palindrome - 0] : ";
                cin>> task;

                // Small Mutation                
                if (task == "SMutation"){
                    char a, b;   int n, m;
                    cout<<"\nTell me what do you want to change? [A C 3 4] {it means replace 3 A with C in the 4th DNA} : ";
                    cin>>a>>b>>n>>m;
                    cell.jahesh_koochak(a,b,n,m-1);
                }

                // Big mutation
                else if (task == "BMutation"){
                    string a, b;     int m, n;
                    cout<<"\nTell me what do you want to change? [A 2 B 3] {it means replace A in 2nd DNA with B in 3rd DNA} : ";
                    cin>>a>>m>>b>>n;
                    cell.jahesh_bozorg(a,m-1,b,n-1);
                }

                // Rever
                else if (task == "Reversion"){
                    string a;       int m;
                    cout<<"\nTell me what do you want to change? [A 4] {it reverses the A in the 4th DNA} : ";
                    cin>>a>>m;
                    cell.jahesh_makoos(a,m-1);
                }

                else if (task == "Palindrome"){
                    int m;
                    cout<<"\nTell me which Chromosome do you want me to process : ";
                    cin>>m;
                    cell.palindromeFounder(m-1);
                }       

                else if(task == "0"){
                    break;
                } 
            
                else{
                cout<<"Invalid Input \n";
            }
        }            
    }

    // 4- Exit [E]
    else if(response == 'E'){
        cout<<"\nWish to see you soon ;)\n";
        break;
    }

    // Invalid input
        else{
            cout<<"Invalid input";
        }
    
    }

    return 0;
}
