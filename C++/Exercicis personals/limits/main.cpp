#include	<iostream>
#include	<string>
#include	<limits>
using	namespace	std;

int	main()	{
    string	nom,	ciutat;
    int	edat;
    cout	<<	"Nom:	"	<<	endl;
    getline(cin,nom);
    cout	<<	"Edat:	"	<<	endl;
    cin	>>	edat;
    cout	<<	"Ciutat:	"	<<	endl;
    cin.ignore(numeric_limits<streamsize>::max(),	'\n');
    getline(cin,ciutat);
    cout	<<	"Nom:	"	<<		nom	<<	"	Edat:	"	<<		edat	<<		"	Ciutat:	"<<		ciutat	<<	endl;

    return	0;
}
