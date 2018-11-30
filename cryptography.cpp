#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


using namespace std;


void gerarMatriz( char matriz[][26])
{

	int xx = 0, yx = 0;

	for (int i = 'a'; i <= 'z'; i++)
	{
		for (char j = i; j <= 'z'; j++)
		{
			matriz[xx][yx] = j;
			yx++;
		}
		for (char j = 'a'; j < i; j++)
		{
			matriz[xx][yx] = j;
			yx++;
		}
		yx = 0;
		xx++;
	}
}

void criptograficar( ifstream &arqLeitura, int numLinhas, char palavraChave[], char cripMatriz[][26] )
{
	ofstream arqGravacao;
	arqGravacao.open( "saida_dados.txt", ofstream::out);
	
	char linhaArquivo[1000];
	int linha, coluna;
	int j = 0;
	
	cout << "		        ======================================" << endl;
	cout << "\n			Chave: ";
	arqLeitura >> palavraChave;
	cout << palavraChave << endl;

	cout << "			numero de linhas: ";
	arqLeitura >> numLinhas;
	cout << numLinhas << endl<< endl;
	
	cout << "		        ======================================" << endl;	
	arqLeitura.getline(linhaArquivo, 1000);
	cout << "			"<< linhaArquivo << endl;
	Sleep(500);
	
	for (int e = 0; e < numLinhas; e++)
	{

		arqLeitura.getline(linhaArquivo, 1000);
		cout << "			"<< linhaArquivo << endl;
		Sleep(500);

		j = 0;

		for (int i = 0; i < strlen(linhaArquivo); i++)
		{
			if(linhaArquivo[i] == ' ')
				arqGravacao << " ";
			else
			{
				linha = palavraChave[j];
				coluna = linhaArquivo[i];
				j++;

				if (j == strlen(palavraChave))
				{
					j = 0;
				}

				arqGravacao << cripMatriz[linha - 97][coluna - 97];
			}

		}

		arqGravacao << endl;
	}
	cout << endl;
	cout << "		        ======================================" << endl << endl;	
	Sleep(1500);
	cout << "               		Arquivo Cripitografado com Sucesso !!!" << endl << endl;
	cout << "		        ======================================" << endl << endl;
	
	ifstream arqCripMostrar;
	arqCripMostrar.open( "saida_dados.txt", ifstream::in);
	
	for(int i = 0; i < numLinhas; i++){
		arqCripMostrar.getline(linhaArquivo, 1000);
		cout << "			"<< linhaArquivo << endl;
		Sleep(500);
	}
	Sleep(3000);
	arqCripMostrar.close();
	arqGravacao.close();
}



int main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	system("color A");
	
	ifstream arqLeitura;
	
	int numLinhas, opcao;
	char palavraChave[50];
	char cripMat[26][26];

	gerarMatriz( cripMat );

	
	
	do
	{	
		arqLeitura.open( "entrada_dados.txt", ifstream::in);
		
		system("cls");
		
		cout << "		=====================================================================================" << endl;
		cout << "		                                                                				     " << endl;
		cout << "		   000000000  00000000    00   0000000         0000000000  0000000000  000000        " << endl;
		cout << "		   00         00     00   00   00     00       00          00      00  00    00      " << endl;
		cout << "		   00         00     00   00   00     00       00          00      00  00     00     " << endl;
		cout << "		   00         0000000     00   0000000         00          00      00  00     00     " << endl;
		cout << "		   00         00   00     00   00        0000  00          00      00  00     00     " << endl;
		cout << "		   00         00    00    00   00              00          00      00  00    00      " << endl;
		cout << "		   000000000  00     00   00   00              0000000000  0000000000  000000        " << endl;
		cout << "		                                                                				     " << endl;
		cout <<	"		=====================================================================================" << endl;
		
		cout <<endl;
		
		cout << "				   1 ------ Criptogragfar o Arquivo ------ " << endl;
		cout << "				   0 ------          Sair           ------ " << endl;
		cout << endl;
		cout << endl;
		cout << "				   Opcao => ";
		cin >> opcao;
		cout << endl;
		
		system("cls");
		
		switch(opcao)
		{
			case 1: 
				criptograficar( arqLeitura, numLinhas, palavraChave, cripMat);
				arqLeitura.close();
				break;
			
			case 0:
				opcao = 0;
				break;
			
			default:
				cout << "Opção inválida!!!" << endl;
				break;
		}
		
		
	}
	while( opcao != 0);
	
	//system("cls");
	
	return 0;
}
