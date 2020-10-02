#include<iostream>
#include<math.h>
using namespace std;

float encrypt[3][1], decrypt[3][1], x[3][3], y[3][3], z[3][3], mes[3][1];


void encryption();
void decryption();
void getKey();
void inverse();

void encryption()
{
    int i,j,k;
    for(i = 0; i < 3; i++) 
    {
        for(j = 0; j < 1; j++)
        {
            for(k = 0; k < 3; k++)
            {
                encrypt[i][j] += x[i][k] * mes[k][j];
            }
        }
    }
    cout<<"\nEncrypted Text is :";
    for(i = 0; i < 3; i++)
    {
        cout<<(char)(fmod(encrypt[i][0], 26) + 97);
    }
    cout<<"\n";

}

void decryption() 
{
	int i, j, k;
	inverse();
	for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 1; j++)
        {
			for(k = 0; k < 3; k++)
            {
				decrypt[i][j] += y[i][k] * encrypt[k][j];
            }
        }
    }
	cout<<"\nDecrypted text is: ";
	for(i = 0; i < 3; i++)
    {
		cout<<(char)(fmod(decrypt[i][0], 26) + 97);
    }
	cout<<"\n";
}

void getKey() 
{
	int i, j;
	char msg[3];

	cout<<"\nEnter a 3 letter text: ";
	cin>>msg;
	
	for(i = 0; i < 3; i++)
    {
		mes[i][0] = msg[i] - 97;
    }
 
	cout<<"Enter 3x3 matrix for key \n";
	
	for(i = 0; i < 3; i++)
    {
		for(j = 0; j < 3; j++) 
        {
			cin>>x[i][j];
			z[i][j] = x[i][j];
		}
    }
}

void inverse() 
{
	int i, j, k;
	float p, q;
	
	for(i = 0; i < 3; i++)
    {
		for(j = 0; j < 3; j++) 
        {
			if(i == j)
				y[i][j]=1;
			else
				y[i][j]=0;
		}
    }
		
	for(k = 0; k < 3; k++) 
    {
		for(i = 0; i < 3; i++) 
        {
			p = z[i][k];
			q = z[k][k];
				
			for(j = 0; j < 3; j++) 
            {
				if(i != k) 
                {
					z[i][j] = z[i][j]*q - p*z[k][j];
					y[i][j] = y[i][j]*q - p*y[k][j];
				}
			}
		}
	}
	
	for(i = 0; i < 3; i++)
    {
		for(j = 0; j < 3; j++)
        {
			y[i][j] = y[i][j] / z[i][i];
        }
    }
	
	cout<<"\n\nInverse Matrix is:\n";
	for(i = 0; i < 3; i++) 
    {
		for(j = 0; j < 3; j++)
        {
			cout<<y[i][j]<<" ";
        }
		
		cout<<"\n";
	}
}
 

int main()
{
    getKey();
    encryption();
    decryption();
}