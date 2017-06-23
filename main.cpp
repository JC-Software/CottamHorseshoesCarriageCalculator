#include <iostream>
/*#include <cstdio>   // needed?
#include <cstdlib>  // needed?*/
#include <math.h>
#include <windows.h> //needed for clear screen

#include "math.h"
#include "main.h"

using namespace std;

int main()
{
    for (;;)
    {
        float fPackingCharge    = 1.1;      // amount to add on to cost

        clear_screen();

        cout << "To Exit Enter a negative number" << endl;  //program will loop until a negative number is entered
        cout << "Enter Weight:" << endl;    //get consignment weight
        int nWeight;
        cin >> nWeight;

        if (nWeight<=0)                      // break out of loop to end program if negative number entered
        {
            break;
        }

        cout << "Enter minimum First 4 characters of Postcode (without Spaces)" << endl;    //get consignment postcode
        char cPostcode1,cPostcode2,cPostcode3,cPostcode4;
        char szPostcode[8];
        cin.getline(szPostcode,8);
        cin >> cPostcode1;
        cin >> cPostcode2;
        cin >> cPostcode3;
        cin >> cPostcode4;

        //check what's in cPostcode1-4
        cout << " p1: " << cPostcode1 << " p2: " << cPostcode2 << " p3: " << cPostcode3 << " p4: " << cPostcode4 << endl;
        cout << "szPostcode: " << szPostcode << endl;

        float fTuffsCost  = round(fTuffs(nWeight,cPostcode1,cPostcode2,cPostcode3,cPostcode4),0.01);      //fetch cost prices
        float fUkMailCost = round(fUKMail(nWeight,cPostcode1,cPostcode2,cPostcode3,cPostcode4),0.01);

        if (fTuffsCost==0)          // if postcode not in program show error warning message
        {
            cout << endl << "!Postcode not yet in database!" << endl <<
                "RESULTS WILL NOT BE VALID" << endl << endl;
        }

        /*  Compare and output Cost prices
         *  and charge prices to the user
         */

        cout << endl;
        cout << "For weight of: "  << nWeight   << " Kg             "     << endl;
        cout << "Tuffnells Cost: " << (char)156 << fTuffsCost   << "    " << endl;     // Show tuffs cost to user // (char)156 is £ sign
        cout << "UK Mail Cost: "   << (char)156 << fUkMailCost  << "    " << endl;     // show UKMail Cost

        //Charge Price Program
        float fChargePrice = 0;
        char cUse = 0;                       // tuffs = 1, UKMail = 2
        if (fTuffsCost < fUkMailCost)                                       // determine if tuffs is cheaper
        {
            fChargePrice = round((fTuffsCost*fPackingCharge),0.25);         //apply packing charge if tuffs cheapest rounded up to 0.25/25p
            cUse = 't';
        }
        else
        {
            fChargePrice = round((fUkMailCost*fPackingCharge),0.25);        //apply packing charge if UKMail cheapest
            cUse = 'u';
        }

        if (fChargePrice <=13.5)                                    // apply minimum carriage charge
        {
            fChargePrice = 13.5;
        }

        cout << "Charge Price: " << (char)156 << fChargePrice << endl;      // show price to charge
        cout << "Using: " ;
        if (cUse=='t')
        {
            cout << "Tuffnells          ";
        }
        if (cUse=='u')
        {
            cout << "UKMail             ";    //white space to over type previous tuffnells
        }

        cout << endl;

        system ("PAUSE");       //dont like system
    }
    cin.get ();

    return 0;
}


void clear_screen ( void )
{
    DWORD n;                         /* Number of characters written */
    DWORD size;                      /* number of visible characters */
    COORD coord = {0};               /* Top left screen position */
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    /* Get a handle to the console */
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

    GetConsoleScreenBufferInfo ( h, &csbi );

    /* Find the number of characters to overwrite */
    size = csbi.dwSize.X * csbi.dwSize.Y;

    /* Overwrite the screen buffer with whitespace*/
    FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
    GetConsoleScreenBufferInfo ( h, &csbi );
    FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

    /* Reset the cursor to the top left position */
    SetConsoleCursorPosition ( h, coord );
}

