#include "DataStructure/SparseMatrix.h"

int main()
{
    int r,c;
    cin>>r>>c;
    SparseMatrix sm(r,c);
    sm.ShowMatrix();
}