#ifndef H_HEIGHT
#define H_HEIGHT



class Height
{
	public :
		//------Methode de Base-------
		Height();								// un Constructeur
		Height(const Height &);					//Constructeur par copie
		Height & operator=(const Dvector &);	//operateur d'affectation par copie
		~Height();								//Destructeur
		//----------------------------
		double & operator()(int x, int y);		//Foncteur
	private :
		int _xSize;
		int _ySize;
		Dvector _vec;
};














#endif
