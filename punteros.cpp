#include <iostream>
using namespace std;

        /* PUNTO 1 */
void cambiar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* funciones simples */
int doble(int x){
    return x * 2;
}

int triple(int x){
    return x * 3;
}

int main(){
    int op;

    do{
        cout << "\n1 intercambiar";
        cout << "\n2 suma arreglo";
        cout << "\n3 mayor";
        cout << "\n4 operar";
        cout << "\n5 memoria";
        cout << "\n0 salir\n";
        cin >> op;


        if(op == 1){
            int a,b;
            cin >> a >> b;

            cambiar(&a,&b);

            cout << a << " " << b << endl;
        }

        /* PUNTO 2 */
        if(op == 2){
            int n;
            cin >> n;

            int *p = new int[n];
            int suma = 0;

            for(int i=0;i<n;i++){
                cin >> *(p+i);
                suma = suma + *(p+i);
            }

            cout << "suma: " << suma << endl;

            delete[] p;
        }

        /* PUNTO 3 */
        if(op == 3){
            int n;
            cin >> n;

            if(n == 0){
                cout << "vacio\n";
            }else{
                int *p = new int[n];

                for(int i=0;i<n;i++){
                    cin >> *(p+i);
                }

                int m = *p;

                for(int i=1;i<n;i++){
                    if(*(p+i) > m){
                        m = *(p+i);
                    }
                }

                cout << "mayor: " << m << endl;

                delete[] p;
            }
        }

        /* PUNTO 4 */
        if(op == 4){
            int n;
            cin >> n;

            int *p = new int[n];

            for(int i=0;i<n;i++){
                cin >> *(p+i);
            }

            int opc;
            cout << "1 doble 2 triple: ";
            cin >> opc;

            for(int i=0;i<n;i++){
                if(opc == 1){
                    *(p+i) = doble(*(p+i));
                }else{
                    *(p+i) = triple(*(p+i));
                }
            }

            for(int i=0;i<n;i++){
                cout << *(p+i) << " ";
            }
            cout << endl;

            delete[] p;
        }

        /* PUNTO 5 */
        if(op == 5){
            float x;
            cin >> x;

            int *pi = (int*)&x;
            char *pc = (char*)&x;

            cout << "direccion: " << &x << endl;

            cout << "como entero: " << *pi << endl;

            cout << "bytes: ";
            for(int i=0;i<sizeof(float);i++){
                cout << (int)*(pc+i) << " ";
            }
            cout << endl;
        }

    }while(op != 0);

    return 0;
}