#include <iostream>
#include <fstream>
#include <cmath>
#include <windows.h>
#include <time.h>

using namespace std;

string input, new_input, key, str, askstr;

void ask(int lim){
	int i, n = 1;
	
	srand(time(NULL));
	
	while (n % 2 != 0){
		n = rand() % lim;
	}
	
	ifstream file("data.txt");
  
  	for(i = 0; i < n; i++){
  		getline(file, askstr);
	}
  
	getline(file, askstr);
	
	int e = rand() % 5;
	
	if (askstr.length() > 13){
		if (askstr[askstr.length()-1] == '?'){
			if(e == 0){
				cout << "Mas o que você acha sobre "<< askstr << endl;
			} else if (e == 1){
				cout << "Mudando de assunto, "<< askstr << endl;
			} else if (e == 2){
				cout << "Queria saber sobre "<< askstr << endl;
			} else if (e == 3){
				cout << "Mas... "<< askstr << endl;
			} else if (e == 4){
				cout << "Mas eu queria falar sobre "<< askstr << endl;
			}	
		} else {	
			if(e == 0){
				cout << "Mas o que você acha sobre "<< askstr << "?" << endl;
			} else if (e == 1){
				cout << "Mudando de assunto, "<< askstr << "?" << endl;
			} else if (e == 2){
				cout << "Responda-me sobre "<< askstr << "?" <<endl;
			} else if (e == 3){
				cout << "Mas responda-me sobre "<< askstr << "?" << endl;
			} else if (e == 4){
				cout << "Mas eu queria que você me respondesse sobre "<< askstr << "?" << endl;
			}	
		}
	}
	
	file.close();
}

int lines(){
	int n;
	string line;
	
	ifstream in("data.txt");
	
	for(n = 0; getline(in, line); n++); // VÊ QUANTAS LINHAS TEM 
	
	in.close();
	
	return n;
}

int possible(int i_pos, int pos,  int error){
	int i;
	if(input.length() > 3){
		for (i = i_pos + 1; i < input.length(); i++){ //Coloca de onde começou
			if(pos < key.length()){
				if (error < 4){ //O máximo de erros é três
					//cout << key << endl;
					//cout << " error: "<< error << " ";
					//cout <<" pos: " << pos<< " " << " i: "<< i <<endl;
					if (input[i] == key[pos]){
						pos++;
					} else {
						if(input[i] == ' '){
							pos++;
						} else {
							pos++;
							i--;
							error++;
						}
	
					}
				}
			} else {
				break;
			}
		}
	} else {
		if(input.compare(key)){
			return 0;
		} else {
			return 1;
		}
	}
	
	
	if(key.length() < 3){
		if(i < input.length()){
			if(input[i] != ' '){
				return 0;
			}
		}
	}
	
	if (error < 4){
		return 1;
	} else {
		return 0;
	}
}

int comp (){
	for(int i = 0; i < input.length() -1; i++){
						
			if (input[i] == key[0]){ // Achou possível candidato
				if (i > 0){
					if(input[i-1] == ' '){
						if(possible(i, 1, 0)){
							return 1;
						}
					}
				} else{
					if(possible(i, 1, 0)){
						return 1;
					}
				}	
			}

	}
}

int hunt(){
	int i = 0, e;
	
	srand(time(NULL));
	
	ifstream file("data.txt");
  
  	for (i = 0; getline(file, key); i++){
		if(i % 2 == 0){
			if (comp()){
				
				e = rand() % 5;
				
				getline(file, key);
				
				if (e == 0){
					cout << "Hm, " << key << endl;
				}else if(e == 1){
					cout << "Ah... " << key << "..." << endl;
				}else if(e == 2){
					cout << "Ah, " << key << endl;
				}else if(e == 3){
					cout << key << ", acho..." << endl;
				}else if(e == 4){
					cout << key << endl;
				}	
				
				break;
			}
  		}
	}
	
	file.close();
	
	return i;
}

int main(){
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	int n, i, e, c;
	
	while(1){
	
	n = lines(); // LINHAS DO PROGRAMA

	cout << "VOCÊ: ";
	
	getline(cin, input); // PEGA INPUT DO USUÁRIO
  	
  	i = hunt(); // CAÇA PALAVRA PRA COMPARAR
  	
	ofstream out;

  	out.open("data.txt", ios_base::app);
  	
  	srand(time(NULL));
  	
	if (n == i){
		e = rand() % 5;
		
		size_t found = input.find_last_of(' ');
		
		if (input[input.length()-1] == '?'){
			if (e == 0){
				cout << "Mas " << input.substr(found+1, input.length()-(found+1)) << endl;
			}else if(e == 1){
				cout << "Espere, mas " << input.substr(found+1, input.length()-(found+1)) << endl;
			}else if(e == 2){
				cout << "Posso saber primeiro sobre " << input.substr(found+1, input.length()-(found+1)) << endl;
			}else if(e == 3){
				cout << "Eu queria perguntar: " << input.substr(found+1, input.length()-(found+1)) << endl;
			}else if(e == 4){
				cout << "Hm, responda-me sobre " << input.substr(found+1, input.length()-(found+1)) << endl;
			}		
		} else {	
			if (e == 0){
				cout << "Hã? "<< input.substr(found+1, input.length()-(found+1)) << "?" << endl;
			}else if(e == 1){
				cout << "Oi? "<< input.substr(found+1, input.length()-(found+1)) << "..?" << endl;
			}else if(e == 2){
				cout << input.substr(found+1, input.length()-(found+1)) << "? Não entendi..." << endl;
			}else if(e == 3){
				cout << input.substr(found+1, input.length()-(found+1)) << "? Como?" << endl;
			}else if(e == 4){
				cout << input.substr(found+1, input.length()-(found+1)) << "? Pode explicar?" << endl;
			}	
		}
		
		cout << "VOCÊ: ";
	
		getline(cin, new_input);
	 
		i = hunt();	
		
	} else {
		c = rand() % 3;
		if (c == 0){
			ask(n); //CHANCE ALEATÓRIA PRA PERGUNTAR ALGO
		}
	}
	

		
	if(n == i){
		out << endl << input << endl; 
		out << new_input; // coloca novo input se ele não for encontrado no data
		c = rand() % 3;
		if (c == 0){
			ask(n+2); //CHANCE ALEATÓRIA PRA PERGUNTAR ALGO
		}
	}	 	
	
	out.close();
	
	}

  	return 0;
}
