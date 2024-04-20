#include<iostream>
#include<string>
#include <cstring>
#include <conio.h>
#include <ctime>
#include<fstream>
using namespace std;


//mails
class mail {


protected:
	int shipmentid;
	string name;
	string time;
	int size;
	int arrid[30];
	string arrtime[30];




public:

	//default 
	mail()
	{
		shipmentid = 0;
		name = "";
		time = "";
		size = 0;

	}


	//parameterized
	mail(int i, string n, string t, int ar, int ti, int s)
	{

		shipmentid = i;
		name = n;
		time = t;
		arrid[size] = ar;
		arrtime[size] = ti;
		size = s;

	}


	//destructor
	 virtual ~mail()
	{

		cout << "";

	}

	//setter
	void setshipmentid(int s)
	{
		shipmentid = s;
	}

	void setsize(int s)
	{
		size = s;
	}

	void setarray(int a)
	{
		arrid[size] = a;
	}

	void setname(string n)
	{
		name = n;
	}

	void settime(string t)
	{
		time = t;
	}

	void setarray(string a)
	{
		arrtime[size] = a;
	}

	//getters
	int getshipmentid()
	{
		return shipmentid;
	}

	int getsize()
	{
		return size;
	}

	int getarray()
	{
		return arrid[size];
	}

	string getname()
	{
		return name;
	}

	string gettime()
	{
		return time;
	}


	string getarray1()
	{
		return arrtime[size];
	}



	//function
	 virtual void showdetails()
	{


		cout << endl;
		cout << " How many shipment ids are going to be delivered : ";
		cin >> size;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " Enter the shipment id which is going to be delivered : ";

			cin >> arrid[i];
		}

		cout << endl;
		for (int j = 0; j < size; j++)
		{

			cout << " Please mention the time at which parcel are going to be dispatched : ";
			cin >> arrtime[j];
		}
		cout << endl;





	}





};


//bounced mails
class bouncemail : public mail {


protected:

	string gpo;
	string raddress;
	string saddress;



public:

	//default
	bouncemail()
	{
		gpo = "";
		raddress = "";
		saddress = "";
		size = 0;
		arrid[size] = 0;

	}


	//parameterized
	bouncemail(string g, string r, string s, int i, int ar )
	{

		gpo = g;
		raddress = r;
		saddress = s;
		size = i;
		arrid[size] = ar;



	}

	virtual  ~bouncemail()
	{

		cout << "";

	}


	//setters
	void setgpo(string g)
	{
		gpo = g;
	}

	void setreciever(string r)
	{
		raddress = r;
	}

	void setsender(string g)
	{
		saddress = g;
	}

	void setsize(int s)
	{
		size = s;
	}

	void setarray(int a)
	{
		arrid[size] = a;
	}


	//getters
	int getsize()
	{
		return size;
	}

	int getarray()
	{
		return arrid[size];
	}


	string getgpo()
	{
		return gpo;
	}

	string getreciever()
	{
		return raddress;
	}

	string getsender()
	{
		return saddress;
	}


	//function
	 virtual void show()
	{

		cout << " The mails which are bounced today " << endl;
		cout << " How many mails are dispatched : ";
		cin >> size;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " Enter the shipment id : ";

			cin >> arrid[i];
		}
		cout << " From which gpo the mails have been dispatched : ";
		cin >> gpo;
		cout << endl;
		cout << " Enter the reciever address : ";
		cin >> raddress;
		cout << endl;
		cout << " Enter the sender address : ";
		cin >> saddress;
		cout << endl;
		cout << " If the mails are successfully recieved by the reciver, Thankyou, or else take the parcels back to gpo " << endl;
		cout << endl;

	}


};


//return mails
class returnedmail : public mail {


protected:
	string raddress;
	string saddress;
	fstream mff;

public:
	//default
	returnedmail()
	{

		raddress = "";
		saddress = "";

	}


	//parameterized
	returnedmail(string r, string s)
	{

		raddress = r;
		saddress = s;

	}

	//destructor
	virtual ~returnedmail()
	{

		cout << "";

	}

	//setters
	void setreciever(string r)
	{
		raddress = r;
	}

	void setsender(string g)
	{
		saddress = g;
	}


	//getters
	string getreciever()
	{
		return raddress;
	}

	string getsender()
	{
		return saddress;
	}


	//function
	 virtual void function()
	{

		 mff.open("returnmail.txt", ios::app | ios::out);
		char opt, Y, N;
		cout << " How many mails are returned back : ";
		cin >> size;
		mff << size;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " Enter the shipment id which is not delivered : ";

			cin >> arrid[i];
			mff << arrid[i];
		}

		cout << endl;
		for (int j = 0; j < size; j++)
		{

			cout << " Please mention the time at which parcel were there : ";
			cin >> arrtime[j];
			mff << arrtime[j];

		}
		cout << endl;

		cout << " Send parcel again at reciver address " << endl;
		cout << " Is parcel recived (Y/N) : ";
		cin >> opt;
		if (opt == 'Y')
		{
			cout << " parcel, successfully recived!! " << endl;
		}

		else if (opt == 'N')
		{
			cout << " Return the parcel to senders address " << endl;
			cout << " Enter the senders adress : ";
			cin >> saddress;
			cout << " The parcel will be sent to sender shortly " << endl;

		}


		mff.close();

	}



};



//class of mailservice
class mailservice {



protected:
	string city;
	double charges;
	string address;
	string raddress;
	mail ml;


public:

	//default constructor
	mailservice()
	{
		city = "";
		charges = 0;
		address = "";
		raddress = "";

	}


	//parameterized constructor
	mailservice(string c, int ch, string ad, string r, mail mi)
	{


		city = c;
		charges = ch;
		address = ad;
		raddress = r;
		ml = mi;

	}


	//destructor
	~mailservice()
	{

		cout << "";

	}


	//setters
	void setcity(string ci)
	{
		city = ci;
	}

	void setmail(mail m)
	{
		ml.setshipmentid(m.getshipmentid());
	}



	void setcharges(int c)
	{

		charges = c;
	}

	void setaddress(string a)
	{
		address = a;
	}


	void setrecieveraddress(string ra)
	{
		raddress = ra;
	}


	//getters
	mail getmail()
	{
		return ml;
	}

	string getcity()
	{
		return city;
	}


	int getcharges()
	{

		return charges;

	}

	string getaddress()
	{

		return address;
	}


	string getrecieveraddress()
	{
		return raddress;
	}


	//function
	void withincity()
	{

		double weight;
		cout << " Enter your city : ";
		cin >> city;

		cout << " your shipment id is : " << ml.getshipmentid();
		cout << endl;


		cout << " Enter your address : ";
		cin >> address;


		cout << endl;


		cout << " Enter recievers address : ";
		cin >> raddress;


		cout << endl;

		cout << " Rate of fee for weight upto 250g is 51 and for 500g is 64 and for 500g is 26 " << endl;
		cout << " enter weight : ";
		cin >> weight;
		cout << endl;
		if (weight == 250)
		{
			charges = 51;
			cout << " The charges are : " << charges;

		}

		else if (weight == 500)
		{
			charges = 64;
			cout << " The charges are : " << charges;

		}

		else if (weight == 500)
		{
			charges = 26;
			cout << " The charges are : " << charges;

		}



		cout << endl;


	}


};



//class of urgent
class regular : public mailservice {


protected:
	string rcity;


public:

	//default constructor
	regular()
	{
		city = "";
		charges = 0;
		address = "";
		raddress = "";
		rcity = "";

	}


	//parameterized constructor
	regular(string c, int ch, string ad, string ra, string rc)
	{


		city = c;
		charges = ch;
		address = ad;
		raddress = ra;
		rcity = rc;

	}


	//destructor
	~regular()
	{

		cout << "";

	}


	//setters
	void setcity(string ci)
	{
		city = ci;
	}



	void setcharges(int c)
	{

		charges = c;
	}

	void setaddress(string a)
	{
		address = a;
	}

	void setrecieveraddress(string ra)
	{
		raddress = ra;
	}

	void setrecievercity(string ci)
	{
		rcity = ci;
	}


	//getters
	string getcity()
	{
		return city;
	}


	int getcharges()
	{

		return charges;

	}

	string getaddress()
	{

		return address;
	}


	string getrecieveraddress()
	{
		return raddress;
	}


	string getrecievercity()
	{
		return rcity;
	}

	//function
	void onedayservice()
	{

		double weight;

		cout << " Enter your city : ";
		cin >> city;

		cout << " Enter recivers city : ";
		cin >> rcity;


		cout << endl;


		cout << " Enter the address : ";
		cin >> address;

		cout << endl;

		cout << " Enter the recievers address : ";
		cin >> raddress;


		if (rcity != city)
		{


			cout << " Rate of fee for weight upto 250g is 86 and for 500g is 132 and for 500g is 43 " << endl;
			cout << " enter weight : ";
			cin >> weight;
			cout << endl;
			if (weight == 250)
			{
				charges = 86;
				cout << " The charges are : " << charges;

			}

			else if (weight == 500)
			{
				charges = 132;
				cout << " The charges are : " << charges;

			}

			else if (weight == 500)
			{
				charges = 43;
				cout << " The charges are : " << charges;

			}




		}


		cout << endl;


	}


};




//class of urgent
class urgent : public mailservice {


protected:
	string rcity;


public:

	//default constructor
	urgent()
	{
		city = "";
		charges = 0;
		address = "";
		raddress = "";
		rcity = "";

	}


	//parameterized constructor
	urgent(string c, int ch, string ad, string ra, string rc)
	{


		city = c;
		charges = ch;
		address = ad;
		raddress = ra;
		rcity = rc;

	}


	//destructor
	~urgent()
	{

		cout << "";

	}


	//setters
	void setcity(string ci)
	{
		city = ci;
	}



	void setcharges(int c)
	{

		charges = c;
	}

	void setaddress(string a)
	{
		address = a;
	}

	void setrecieveraddress(string ra)
	{
		raddress = ra;
	}

	void setrecievercity(string ci)
	{
		rcity = ci;
	}


	//getters
	string getcity()
	{
		return city;
	}


	int getcharges()
	{

		return charges;

	}

	string getaddress()
	{

		return address;
	}


	string getrecieveraddress()
	{
		return raddress;
	}


	string getrecievercity()
	{
		return rcity;
	}

	//function
	void urgentservice()
	{
		double weight;
		cout << " For urgent service, there is 20% charges compared to mailservice mail service " << endl;
		cout << endl;

		cout << " Enter your city : ";
		cin >> city;

		cout << " Enter recivers city : ";
		cin >> rcity;


		cout << endl;


		cout << " Enter the address : ";
		cin >> address;

		cout << endl;

		cout << " Enter the recievers address : ";
		cin >> raddress;

		if (rcity == city)
		{

			cout << " Rate of fee for weight upto 250g is 51 and for 500g is 64 and for 500g is 26 " << endl;
			cout << " enter weight : ";
			cin >> weight;
			cout << endl;
			if (weight == 250)
			{
				charges = 51;
				cout << " The charges are : " << charges * 0.2;

			}

			else if (weight == 500)
			{
				charges = 64;
				cout << " The charges are : " << charges * 0.2;

			}

			else if (weight == 500)
			{
				charges = 26;
				cout << " The charges are : " << charges * 0.2;

			}

		}



		else if (rcity != city)
		{


			cout << " Rate of fee for weight upto 250g is 86 and for 500g is 132 and for 500g is 43 " << endl;
			cout << " enter weight : ";
			cin >> weight;
			cout << endl;
			if (weight == 250)
			{
				charges = 86;
				cout << " The charges are : " << charges * 0.2;

			}

			else if (weight == 500)
			{
				charges = 132;
				cout << " The charges are : " << charges * 0.2;

			}

			else if (weight == 500)
			{
				charges = 43;
				cout << " The charges are : " << charges * 0.2;

			}




		}


		cout << endl;







	}


};



class headoffice {


protected:
	char name[30];
	char contact[30];


public:

	//default constructor
	headoffice()
	{
		name[30] = NULL;
		contact[30] = NULL;

	}


	//parameterized constructor
	headoffice(char n, char c)
	{

		name[30] = n;
		contact[30] = c;

	}


	//destructor
	~headoffice()
	{


	}


	//setters
	void setname(char na)
	{
		name[30] = na;
	}

	void setcontact(char co)
	{
		contact[30] = co;
	}


	//getters
	char getname()
	{
		return name[30];
	}


	char getcontact()
	{
		return contact[30];
	}



	//function
	void addemployee()
	{


		cout << " Enter your name : ";
		cin >> name;

		cout << endl;

		cout << " Enter your contact no : ";
		cin >> contact;

		cout << endl;

		cout << " Employee name is : " << name << endl;
		cout << " Employee contact is : " << contact << endl;

		cout << endl;


	}



	void updateemployee()
	{

		string opt;

		cout << " Whether you want to edit your name or contact or both : ";

		cin >> opt;

		if (opt == "name")
		{

			cin >> name;
			cout << " Name is changed " << endl;


		}

		if (opt == "contact")
		{

			cin >> contact;
			cout << " contact is changed " << endl;


		}

		if (opt == "both")
		{
			cout << " Change your name : ";
			cin >> name;
			cout << " Name is changed " << endl;
			cout << " Change your contact : " << endl;
			cin >> contact;
			cout << " contact is changed " << endl;

		}


		cout << " Name is : " << name << endl;
		cout << " contact is : " << contact << endl;

		cout << endl;


	}


	void delemployee()
	{

		delete name;
		delete contact;

		cout << " The Employee name has been deleted " << endl;
		cout << " The Employee contact has been deleted " << endl;

		cout << endl;


	}





};



//login system
class login {


protected:
	int id;
	string name;
	string password;
	fstream fe;
	fstream h;

public:

	//default constructor
	login()
	{
		id = 0;
		name = "";
		password = "";

	}


	//parameterized constructor
	login(int i, string n, string p)
	{

		id = i;
		name = n;
		password = p;

	}


	//setters
	void setid(int i)
	{
		id = i;

	}


	void setname(string n)
	{

		name = n;

	}

	void setpassword(string p)
	{

		password = p;

	}


	//getters
	int getid()
	{
		return id;
	}

	string getname()
	{
		return name;

	}

	string getpassword()
	{

		return password;

	}


	//function
	void loginsystemhead()
	{

		h.open("headlogin.txt", ios::app | ios::out);

		int id1 = 12;  string password1 = "012345";

		cout << " Enter your ID : ";

		cin >> id;

		h << id;

		if (id == id1)
		{

			cout << " Enter your password : ";

			cin >> password;

			h << password;

			if (password == password1)
			{

				cout << " ************************* WELCOME **************************" << endl;

				cout << endl;

			}

			else if (password != password1)
			{

				cout << " Enter your password again : ";

				cin >> password;

				h << password;

				if (password == password1)
				{

					cout << " ********************* WELCOME **************************" << endl;

					cout << endl;

				}

				
			}

		}


		else if (id != id1)
		{

			cout << " Enter your id again : ";

			cin >> id;

			h << id;

			cout << " Enter your password : ";

			cin >> password;

			if (password == "012345")
			{

				cout << " ***************** WELCOME **************************" << endl;

				cout << endl;

			}

			else if (password != "012345 ")
			{

				cout << " Enter your password again : ";

				cin >> password;

				h << password;

				if (password == "012345")
				{

					cout << " ***************** WELCOME **************************" << endl;

					cout << endl;

				}


			}


		}


		h.close();

	}



};



//invoice
class invoice {


protected:
	int id;
	double weight;
	string time;
	string ra;
	string sa;
	string contactdetails;
	string contactdetails1;



public:

	//default 
	invoice()
	{
		id = 0;
		weight = 0;
		time = "";
		ra = "";
		sa = "";
		contactdetails = "";
		contactdetails1 = "";

	}

	//parameterized
	invoice(int i, double w, string t, string r, string s, string c, string c1)
	{

		id = i;
		weight = w;
		time = t;
		ra = r;
		sa = s;
		contactdetails = c;
		contactdetails1 = c1;

	}


	//setters
	void setid(int i)
	{
		id = i;

	}


	void setweight(double we)
	{
		weight = we;
	}


	void settime(string ti)
	{

		time = ti;
	}


	void setsenderaddress(string s)
	{

		sa = s;

	}

	void setrecieveraddress(string r)
	{
		ra = r;
	}

	void setcontactdetails(string cd)
	{
		contactdetails = cd;
	}

	void setcontactdetails1(string cd1)
	{
		contactdetails1 = cd1;
	}


	//getters
	int getid()
	{
		return id;
	}

	double getweight()
	{

		return weight;
	}

	string gettime()
	{
		return time;
	}


	string getsenderaddress()
	{
		return sa;
	}

	string getrecieveraddress()
	{
		return ra;
	}

	string getcontactdetails()
	{
		return contactdetails;
	}

	string getcontactdetails1()
	{
		return contactdetails1;
	}



	//funtion
	void showinvoice()
	{


		cout << "Enter your shipment id : ";
		cin >> id;

		cout << endl;

		cout << " Enter your parcels weight : ";
		cin >> weight;

		cout << endl;

		cout << " Enter the shipment time : ";
		cin >> time;

		cout << endl;

		cout << " Enter senders address : ";
		cin >> sa;

		cout << endl;

		cout << " Enter recievers address : ";
		cin >> ra;

		cout << endl;

		cout << " Please provide contact details of sender  : ";
		cin >> contactdetails;

		cout << endl;

		cout << " Please provide contact details of reciever  : ";
		cin >> contactdetails1;

		cout << endl;

	}



};


//postal workers
class postalworker {

protected:
	double finance;
	string stamp;
	string delivery;


public:

	//default constructor
	postalworker()
	{

		finance = NULL;
		stamp = "";
		delivery = "";

	}


	//parameterized constructor
	postalworker(double f, string s, string d)
	{


		finance = f;
		stamp = s;
		delivery = d;

	}


	//setters
	void setfinance(double f)
	{

		finance = f;
	}

	void setstamp(string s)
	{
		stamp = s;
	}

	void setdelivery(string d)
	{
		delivery = d;
	}


	//getters
	double getfinance()
	{
		return finance;
	}


	string getstamp()
	{
		return stamp;

	}


	string getdelivery()
	{
		return delivery;

	}


	//function
	void showpost()
	{
		int count;
		cout << " How many parcels are to deliver today : ";
		cin >> count;

		cout << endl;
		cout << " Enter the areaa where the parcels are to be delivered : ";
		cin >> delivery;
		cout << endl;





	}


};





//class of clerk
class clerk : public postalworker {

public:
	//default constructor
	clerk()
	{
		stamp = "";

	}


	//parametrize construcrir
	clerk(string s)
	{
		stamp = s;
	}


	//setters
	void setstamp(string st)
	{
		stamp = st;
	}

	//getter
	string getstamp()
	{
		return stamp;
	}

	//function
	void calculate()
	{

		cout << " how many parcels are there : ";
		cin >> stamp;

		char opt;
		cout << " Do you want parcels to be stamped (Y/N) : ";
		cin >> opt;
		if (opt == 'Y')
		{
			cout << stamp << " Parcels are stamped and ready to dispatched " << endl;

		}

		else if (opt == 'N')
		{
			cout << " Enter no of parcels to be stamped :";

			cin >> stamp;

			cout << endl;

			cout << " Parcels are ready to dispatch " << endl;

			cout << endl;

		}

	}




};


//class of postman
class postman : public postalworker {


public:
	//default
	postman()
	{

		delivery = "";
	}

	//parameterized
	postman(string d)
	{
		delivery = d;
	}

	//setter
	void setdelivery(string de)
	{
		delivery = de;

	}

	//getter
	string getdelivery()
	{
		return delivery;

	}


	//function
	void post()
	{

		cout << " The parcels are stamped and ready to dispatch " << endl;

		cout << " Enter the parcels postman is going to deliver : ";

		cin >> stamp;

		cout << " Enter the city where postman is going : ";

		cin >> delivery;

		cout << endl;

	}




};



//class of account officer
class accountofficer : public postalworker {

public:

	//default constructor
	accountofficer()
	{
		finance = NULL;

	}


	//parametrize construcrir
	accountofficer(double f)
	{
		finance = f;
	}


	//setters
	void setfinance(double fi)
	{
		finance = fi;
	}

	//getter
	double getfinance()
	{
		return finance;
	}

	//function
	void calculate()
	{

		double count;

		cout << " How many parcels have been dispatched ? ";

		cin >> count;

		cout << endl;

		cout << " How much payment has to be made : ";
		cin >> finance;

		cout << " The total from parcels is : " << finance << endl;
		cout << endl;

	}




};



//payement class
class payment {

protected:
	accountofficer* a;


public:

	//default
	payment()
	{

		a = new accountofficer;

	}

	payment(accountofficer* f)
	{

		this->a = f;

	}



	//setter
	void setaccountofficer(accountofficer aa)
	{
		a->setfinance(aa.getfinance());

	}



	//getter
	accountofficer getaccountofficer()
	{
		return *(this->a);
	}



	void show()
	{

		a->setfinance(2000);

		cout << " The finance is : " << a->getfinance();


		cout << endl;

	}


};


//class of transaction record
class transactionrecord {

protected:
	fstream sen;
	string amount;
	int mails;
	int leftmails;
	int total;
	accountofficer* aff;


public:

	//default
	transactionrecord()
	{

		amount = "";
		mails = 0;
		leftmails = 0;


	}


	//parameterized
	transactionrecord(string a, int m, int l) : total{ 0 }
	{

		amount = a;
		mails = m;
		leftmails = l;

	}


	//setters
	void setamount(string a)
	{
		amount = a;
	}

	void setmail(int m)
	{

		mails = m;
	}

	void setleft(int l)
	{
		leftmails = l;
	}

	void settotal(int t)
	{
		total = t;
	}


	//getters
	int gettotal()
	{
		return total;
	}


	string getamount()
	{
		return amount;
	}

	int getmail()
	{
		return mails;
	}

	int getleftmails()
	{

		return leftmails;
	}


	//function
	void cal()
	{
		sen.open("transactionrecord.txt", ios::app | ios::out);
		accountofficer ac;
		ac.setfinance(456);
		cout << " The total amount is : " << ac.getfinance();
		cout << endl;
		cout << " Enter the amount of which parcels are dispatched : ";
		cin >> amount;
		sen << amount;
		cout << endl;
		cout << " How many mails have been dispatched today : ";
		cin >> mails;
		sen << mails;


		cout << endl;
		cout << " How many mails are returned : ";
		cin >> leftmails;
		cout << endl;
		sen.close();

	}




};



//class of address
class address {

protected:
	string raddress;
	string saddress;
	fstream ass;



public:

	//default
	address()
	{
		raddress = "";
		saddress = "";

	}


	//parameterized
	address(string r, string s)
	{

		raddress = r;
		saddress = s;
	}




	//setters
	void setrecadd(string r)
	{

		raddress = r;
	}


	void setsenadd(string s)
	{
		saddress = s;
	}




	//getters

	string getsetrecadd()
	{
		return raddress;
	}




	string getsenadd()
	{

		return saddress;
	}



	//function
	void function1()
	{

		ass.open("address.txt", ios::app | ios::out);
		cout << " Enter the sender's address : ";
		cin >> saddress;
		ass << saddress;
		cout << endl;
		cout << " Enter the reciever's address : ";
		cin >> raddress;
		ass << raddress;
		cout << endl;
		ass.close();


	}



};



//customer class
class customer {

protected:
	string name;
	string contact;
	address* adr;
	string raddress;
	postalworker* pw;



public:

	//default
	customer()
	{
		name = "";
		contact = "";

	}


	//parameterized
	customer(string n, string c) : raddress{ "" }
	{

		name = n;
		contact = c;

	}


	//setters
	void setnam(string n)
	{

		name = n;

	}


	void setcont(string c)
	{

		contact = c;
	}

	string getradress()
	{
		return raddress;
	}


	//getters
	string getnam()
	{
		return name;
	}

	string getconst()
	{
		return contact;
	}


	//function
	void showdetail1()
	{
		address a;
		postalworker p;
		p.setdelivery("rawalpindi");
		a.setrecadd("Islamabad");

		cout << "  The customer's address is : " << a.getsetrecadd() << endl;
		cout << " The city where the parcels are going to be delivered : " << p.getdelivery();
		cout << " Enter customer's name : ";
		cin >> name;
		cout << endl;
		cout << " Enter customer's contact number : ";
		cin >> contact;
		cout << endl;

	}


};



//class of order
class order {

protected:
	customer cus;
	invoice in;
	string name;
	string contactdetails;
	string address;
	int id;
	int mail;
	fstream fm;


public:

	//default
	order()
	{

		name = "";
		contactdetails = "";
		address = "";
		id = 0;
		mail = 0;



	}


	//parameterized
	order(string n, string c, string a, int i, int m, customer cu, invoice inv)
	{

		name = n;
		contactdetails = c;
		address = a;
		id = i;
		mail = m;
		cus = cu;
		in = inv;

	}

	~order()
	{
		cout << "";
	}


	//setters
	void setname1(string n)
	{
		name = n;

	}

	void setcon(string c)
	{
		contactdetails = c;
	}

	void setad(string a)
	{
		address = a;
	}

	void setid1(int i)
	{
		id = i;
	}

	void setmail1(int m)
	{
		mail = m;

	}

	void setcustomer(customer c)
	{
		cus.setnam(c.getnam());
		cus.setcont(c.getconst());
	}

	void setinvoice(invoice i)
	{
		in.setid(i.getid());
	}



	//getters

	invoice getinvoice()
	{
		return in;
	}


	customer getcustomer()
	{
		return cus;
	}


	string getname1()
	{
		return name;
	}

	string getcon()
	{
		return contactdetails;
	}

	string getad()
	{
		return address;
	}

	int getid1()
	{
		return id;
	}

	int getmail1()
	{
		return mail;
	}


	//function
	void order1()
	{

		fm.open("customerdetails.txt", ios::app | ios::out);
		cus.setnam("ahmed"); cus.setcont("03456");  in.setid(12);
		cout << " your name is : " << cus.getnam();
		fm << cus.getnam();
		cout << endl;
		cout << " Your contact is : " << cus.getconst();
		fm << cus.getconst();
		cout << " Please enter your address : ";
		cin >> address;
		fm << address;
		cout << endl;
		cout << "  your id : " << in.getid();
		fm << in.getid();
		cout << endl;
		cout << endl;
		cout << " Please enter how many mails you want to send : ";
		cin >> mail;
		fm << mail;
		cout << endl;
		cout << " Your order for " << mail << " has been taken!! " << endl;
		cout << endl;
		fm.close();
		cout << endl;

	}


};


//sorting class
class sorting : public postalworker {


protected:
	int size;
	string shipmentid[30];
	string city[30];
	string gpo;
	string name;
	mail* mi;



public:

	//default
	sorting()
	{

		size = 0;
		shipmentid[size] = "";
		city[size] = "";
		gpo = "";

	}

	//parameterized
	sorting(int s, string i, string c, string g) : name{ "" }
	{

		size = s;
		shipmentid[size] = i;
		city[size] = c;
		gpo = g;

	}


	//setters
	void setsize(int s)
	{
		size = s;
	}

	void setname(string n)
	{
		name = n;
	}

	void setshipmentid(string i)
	{
		shipmentid[size] = i;
	}

	void setcity(string c)
	{
		city[size] = c;
	}

	void setgpo(string g)
	{
		gpo = g;
	}


	//getters
	int getsize()
	{
		return size;

	}

	string getname()
	{
		return name;
	}

	string getshipmentid()
	{
		return shipmentid[size];
	}

	string getcity()
	{
		return city[size];
	}

	string getgpo()
	{
		return gpo;
	}


	//function
	void sort1()
	{

		mail m;
		m.setname("ahmed");
		cout << " The name is : " << m.getname();
		cout << endl;
		cout << " How many mails are recieved : ";
		cin >> size;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " Enter the shipment id of mail : ";
			cin >> shipmentid[size];
		}

		for (int i = 0; i < size; i++)
		{
			cout << " To which city : ";
			cin >> city[size];
		}

		cout << " Put the mails of same cities in one bag and the mails of different cities in different bag and then enter their gpo " << endl;
		cout << " Enter the GPO : ";
		cin >> gpo;
		cout << endl;
		cout << " The mails will be sent shortly!!!" << endl;
		cout << endl;

	}



};


//class of GPO
class Gpo {

protected:
	int c;


public:
	//default
	Gpo()
	{

		c = 0;
	}


	//parameterized
	Gpo(int count)
	{
		c = count;

	}


	//setter
	void setcount(int co)
	{
		c = co;
	}


	//getter
	int getcount()
	{
		return c;
	}



	//function
	void showdetail2()
	{

		cout << endl;
		cout << " How many mails have we have to send today to recievers : ";
		cin >> c;
		cout << endl;
		cout << " Please Sort these mails city wise " << endl;
		cout << endl;

	}


};



//tracking system
class tracking
{

protected:
	int id;
	string name;


public:
	//default
	tracking()
	{

		id = 0;
		name = "";
	}

	//parameterized
	tracking(int i, string n)
	{

		id = i;
		name = n;
	}


	//setters
	void setid(int i)
	{
		id = i;
	}

	void setname(string n)
	{
		name = n;
	}



	//getters
	int getid()
	{

		return id;
	}

	string getname()
	{
		return name;
	}


	//function
	void track()
	{

		cout << " Enter your id : ";
		cin >> id;
		cout << endl;
		cout << " Enter your name : ";
		cin >> name;
		cout << endl;
		cout << " Your mail is on the way and it will take 1 day to reach to your destination " << endl;

	}


};



//post office
class postoffice {


protected:
	double rate;
	double weight;
	int size;
	mail* m;
	Gpo* g;
	fstream pff;


public:
	//default
	postoffice()
	{

		rate = 0;
		weight = 0;

	}


	//parameterized
	postoffice(double r, double w) : size{ 0 }
	{

		rate = r;
		weight = w;

	}

	//setters
	void setrate(double r)
	{
		rate = r;
	}

	void setsize(int s)
	{
		size = s;
	}

	void setweight(double w)
	{
		weight = w;
	}

	//getter
	double getrate()
	{
		return rate;
	}

	int getsize()
	{
		return size;
	}

	double getweight()
	{
		return weight;
	}


	//function
	void func()
	{

		pff.open("postoffices.txt", ios::app | ios::out);
		mail m;
		Gpo g;
		m.setsize(10);
		g.setcount(10);
		cout << " How many mails are recieved today : " << m.getsize() << endl;
		pff << m.getsize();
		cout << " How many mails are to be sent to recievers today : " << g.getcount() << endl;
		pff << g.getcount();
		cout << " Registration for parcel is 75 rs " << endl;
		cout << " 1 kg = 100rs " << endl;
		cout << " 3 kg = 175rs " << endl;
		cout << " 5 kg = 250rs " << endl;
		cout << " 10 kg = 370rs " << endl;
		cout << " 15 kg = 500rs " << endl;
		cout << " 20 kg = 620rs " << endl;
		cout << " 25 kg = 750rs " << endl;
		cout << " 30 kg = 875rs " << endl;
		cout << endl;
		cout << " Enter the weight of your parcel : ";
		cin >> weight;
		if (weight == 1)
		{
			rate = 100;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 3)
		{
			rate = 175;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 5)
		{
			rate = 250;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 10)
		{
			rate = 370;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 15)
		{
			rate = 500;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 20)
		{
			rate = 620;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 25)
		{
			rate = 750;
			cout << " You have to pay " << rate << endl;
		}

		if (weight == 30)
		{
			rate = 875;
			cout << " You have to pay " << rate << endl;
		}

		cout << " Thankyou!! " << endl;

		pff.close();

	}




};


//class of feedback
class feedback {

protected:
	int rating;

public:

	//default
	feedback()
	{

		rating = 0;

	}


	//parameterized
	feedback(int r)
	{

		rating = r;

	}

	//destructor
	 virtual ~feedback()
	{

		cout << " ";

	}

	//setter
	void setrat(int r)
	{

		rating = r;

	}

	//getter
	int getrat()
	{

		return rating;

	}



	//function
	 virtual void feedback1()const
	{

		cout << " The rating for the last week was : "  <<rating<< endl;


		cout << endl;

	}




};


//customerfeedback
class customerfeedback : public feedback{

protected:
	string customerfeed;

public:

	//default
	customerfeedback()
	{

		rating = 0;

		customerfeed = "";

	}


	//parameterized
	customerfeedback(int r , string f)
	{

		rating = r;

		customerfeed = f;

	}


	//destructor
	virtual ~customerfeedback()
	{

		cout << "";

	}


	//setter
	void setrat(int r)
	{

		rating = r;

	}

	void setfeed(string fe)
	{

		customerfeed = fe;

	}


	//getter
	int getrat()
	{

		return rating;

	}


	string getfeed()
	{

		return customerfeed;

	}


	//fucntion
	 virtual void custfeed()
	{

		 
		cout << " The rating by the customer  : "   ;

		cin >> rating;

		cout << endl;


		cout << "  The feedback  by customer : " ;

		cin >> customerfeed;
		

		cout << endl;


	}




};



//customerfeedback
class employeefeedback : public feedback {

protected:
	string employeefeed;

public:

	//default
	employeefeedback()
	{

		rating = 0;

		employeefeed = "";

	}


	//parameterized
	employeefeedback(int r, string f)
	{

		rating = r;

		employeefeed = f;

	}


	//destructor
	virtual ~employeefeedback()
	{

		cout << "";

	}


	//setter
	void setrat(int r)
	{

		rating = r;

	}

	void setefeed(string fe)
	{

		employeefeed = fe;

	}


	//getter
	int getrat()
	{

		return rating;

	}


	string getefeed()
	{

		return employeefeed;

	}


	//fucntion
	 virtual void empfeed()
	{

		 cout << " The rating by the employee  : " ;

		 cin >> rating;

		 cout << endl;


		 cout << "  The feedback by employee : " ;

		 cin >> employeefeed;


		 cout << endl;


	}




};



//login system

class Login {
protected:
	string user, pass, new_pass, re_pass;
	int i;
	string** deets;
	fstream log;

public:
	Login() {
		user = "";
		pass = "";
		new_pass = "";
		re_pass = "";

	}

	Login(string User, char* pass, char* new_pass, char* re_pass) {
		user = User;
		pass = pass;
		new_pass = new_pass;
		re_pass = re_pass;
	}

	~Login() {}


	void  username() {
		this->i++;
		cout << "\t\t\t\t\t\t\t\t      Username : ";	cin >> user;  log << user;
	}

	void  password(char a) {
		int i;
		for (i = 0; i < 8; i++) {
			if (i == 0)	cout << "\t\t\t\t\t\t\t\t      Password : ";
			pass[i] = _getch(); 
			log << pass[i];
			cout << '*';

			if ((pass[i] == '\r') && (i < 8)) {
				cout << "\t\t\t\t\t\t\t\t\t                  Your password should be 8 charectors long!!" << endl;
				i = -1;
			}
			else if ((pass[i] == '\b') && (i > 0)) {
				i--; i--;
				cout << "\b\b";
			}
		}
		cout << endl;
	}

	void  ResetPass(char a) {
		string temp, temp1;
		int count, num, lc, uc, sc;
	here:
		count = 0, num = 0, lc = 0, uc = 0, sc = 0;
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t      Password : ";
		for (int i = 0; i < 8; i++) {
			new_pass[i] = _getch();

			cout << '*';
			log << new_pass[i];
			if ((new_pass[i] == '\r') && (i < 8)) {
				cout << endl << "\t\t\t\t\t\t\t\tYour password should be 8 charectors long!!" << endl;
				goto here;
			}
			else if ((new_pass[i] == '\b') && (i > 0)) {
				i--; i--;
				cout << "\b\b";
			}
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			if (!(new_pass[i] >= '0' && new_pass[i] <= '9'))		num++;
			if (!((new_pass[i] >= 'a' && new_pass[i] <= 'z')))		lc++;
			if (!((new_pass[i] >= 'A' && new_pass[i] <= 'Z')))		uc++;
			//	if(!((new_pass[i]>=' '	&&	new_pass[i]<'0'))	||	((new_pass[i]>'9'	&&	new_pass[i]<'A'))	||	((new_pass[i]>'Z'	&&	new_pass[i]<'a')))	sc++;
		}
		if (num == 8) {
			cout << "\t\t\t\t\t\t\t\tYour password should have a Numeric digit" << endl;//cout<<sc<<endl;
			goto here;
		}
		if (lc == 8) {
			cout << "\t\t\t\t\t\t\t\tYour password should have a Lowercase" << endl;
			goto here;
		}
		if (uc == 8) {
			cout << "\t\t\t\t\t\t\t\tYour password should have a Uppercase" << endl;
			goto here;
		}
		/*	if(sc==8){
				cout<<"Your password should have a Special character"<<endl;
				goto here;
			}*/
		cout << "\t\t\t\t\t\t\t\t      Re-enter Password : ";
		for (int i = 0; i < 8; i++) {
			re_pass[i] = _getch(); _putch('*');
			if (re_pass[i] == 13)	break;
			if ((re_pass[i] == '\r') && (i < 8)) {
				cout << endl << "\t\t\t\t\t\t\t\tYour password should be 8 charectors long!!" << endl;
				goto here;
			}
			else if ((re_pass[i] == '\b') && (i > 0)) {
				i--; i--;
				cout << "\b\b";
			}
		}
		cout << endl;
		for (int i = 0; i < 8; i++) {
			if (new_pass[i] != re_pass[i]) {
				cout << "\t\t\t\t\t\t\t\tYour passwords dont match. Please re-enter your password" << endl;
				goto here;
			}
		}

		log.close();

	}





};






//main function
int main()
{
	

	//polymorphism creating pointer objects for feedback class
	customerfeedback cfee;
	employeefeedback efee;
	 
	feedback* e = &cfee;
	feedback* b = &efee;

	
	//polymorphism creating pointer objects for mail class
	bouncemail bl;
	returnedmail ri;

	mail* m = &bl;
	mail* obj = &ri;


	//creating objects
	regular od;
	mailservice cs;
	urgent us;
	headoffice h;
	login l;
	Login L;
	invoice i;
	accountofficer ac;
	clerk c;
	postman p;
	mail object;
	//bouncemail bm;
	//returnedmail rm;
	address ad;
	customer co;
	order ord;
	transactionrecord tr;
	tracking tk;
	sorting so;
	postoffice po;
	Gpo g;
	payment py;
	postalworker pw;


	
	//declaring variables
	char  opt, r, u, o;
	int ch;


	//aggregation new memory allocation:pointer type
	accountofficer* a = new accountofficer();



	//file handling
	fstream transactionrecord;
	fstream address;
	fstream order;
	fstream login;
	fstream returnedmail;

    

	cout << " Head office or Employee or customer (H/E/C) : ";

	cin >> opt;

	if (opt == 'H')
	{

		//calling login system
	    l.loginsystemhead();

		cout << "*********************** HEAD OFFICE ***********************" << endl;

		cout << endl;

		cout << " 1 . add employee " << endl;
		cout << " 2 . update employee " << endl;
		cout << " 3 . delete employee " << endl;
		cout << " 4 . exit " << endl;

		cin >> ch;

		cout << endl;


		if (ch == 1)
		{

			h.addemployee();

			cout << " You want to add , update or delete Employee's name and contact or exit : ";

			cin >> ch;

			if (ch == 1)
			{

				h.addemployee();

			}


			if (ch == 2)
			{
				h.updateemployee();

			}


			if (ch == 3)
			{

				h.delemployee();

			}

			else if (ch == 4)
			{

				exit;

			}


		}



		cout << "*********************** EMPLOYEE **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');

		//calling postalworker function
		pw.showpost();

		//calling clerk function
		c.calculate();

		//postman function
		p.post();

		//calling accountofficer funtion
		ac.calculate();

		//calling payment function
		py.show();

		//calling transaction record function
		tr.cal();

		//calling sorting function
		so.sort1();

		//calling postoffice function
		po.func();

		//calling gpo function
		g.showdetail2();

		//calling mail class function
		object.showdetails();

		//bounce mail function
		bl.show();

		//returnedmail function
		ri.function();


		cout << endl;


		cout << "*********************** CUSTOMER **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');


		//calling address function
		ad.function1();

		//calling customer fucntion
		co.showdetail1();

		//calling order function
		ord.order1();

		//calling invoice
		i.showinvoice();

		cout << "******************** MAIL SERVICES *******************" << endl;

		cout << endl;

		cout << " You want oneday service, regular or urgent service " << endl;

		cout << endl;

		cout << " Press r for regular service , c for within city and u for urgent service : ";

		cin >> opt;



		if (opt == 'r')
		{
			//calling regular mail function
			od.onedayservice();

		}


		else if (opt == 'c')
		{

			//calling mail service function
			cs.withincity();

		}


		else if (opt == 'u')
		{

			//calling urgent mail service
			us.urgentservice();

		}

		cout << "************************** FEEDBACK ****************************" << endl;

		cout << endl;

		//customer feedback
		cfee.custfeed();

		//employee feedback
		efee.empfeed();

		cout << endl;

		cout << endl;

		cout << " ************************** TRACKING ***************************" << endl;

		cout << endl;

		cout << " Do you want to track your order : (Y/N) : ";

		cin >> opt;

		if (opt == 'Y')
		{

			//calling tracker function
			tk.track();

		}

		else if (opt == 'N')
		{

			exit;

		}

		cout << endl;









	}


	
	else if (opt == 'E')
	{

		cout << "*********************** EMPLOYEE **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');

		//calling postalworker function
		pw.showpost();

		//calling clerk function
		c.calculate();

		//postman function
		p.post();

		//calling accountofficer funtion
		ac.calculate();

		//calling payment function
		py.show();

		//calling transaction record function
		tr.cal();

		//calling sorting function
		so.sort1();

		//calling postoffice function
		po.func();

		//calling gpo function
		g.showdetail2();

		//calling mail class function
		object.showdetails();

		//bounce mail function
		bl.show();

		//returnedmail function
		ri.function();


		cout << endl;


		cout << "*********************** CUSTOMER **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');


		//calling address function
		ad.function1();

		//calling customer fucntion
		co.showdetail1();

		//calling order function
		ord.order1();

		//calling invoice
		i.showinvoice();

		cout << "******************** MAIL SERVICES *******************" << endl;

		cout << endl;

		cout << " You want oneday service, regular or urgent service " << endl;

		cout << endl;

		cout << " Press r for regular service , c for within city and u for urgent service : ";

		cin >> opt;



		if (opt == 'r')
		{
			//calling regular mail function
			od.onedayservice();

		}


		else if (opt == 'c')
		{

			//calling mail service function
			cs.withincity();

		}


		else if (opt == 'u')
		{

			//calling urgent mail service
			us.urgentservice();

		}

		cout << "************************** FEEDBACK ****************************" << endl;

		cout << endl;

		//customer feedback
		cfee.custfeed();

		//employee feedback
		efee.empfeed();

		cout << endl;

		cout << endl;

		cout << " ************************** TRACKING ***************************" << endl;

		cout << endl;

		cout << " Do you want to track your order : (Y/N) : ";

		cin >> opt;

		if (opt == 'Y')
		{

			//calling tracker function
			tk.track();

		}

		else if (opt == 'N')
		{

			exit;

		}

		cout << endl;





	}



	else if (opt == 'C')
	{

		cout << "*********************** CUSTOMER **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');


		//calling address function
		ad.function1();

		//calling customer fucntion
		co.showdetail1();

		//calling order function
		ord.order1();

		//calling invoice
		i.showinvoice();


		cout << "******************** MAIL SERVICES *******************" << endl;

		cout << endl;

		cout << " You want oneday service, regular or urgent service " << endl;

		cout << endl;

		cout << " Press r for regular service , c for within city and u for urgent service : ";

		cin >> opt;



		if (opt == 'r')
		{
			//calling regular mail function
			od.onedayservice();

		}


		else if (opt == 'c')
		{

			//calling mail service function
			cs.withincity();

		}


		else if (opt == 'u')
		{

			//calling urgent mail service
			us.urgentservice();

		}

		cout << "************************** FEEDBACK ****************************" << endl;

		cout << endl;

		//customer feedback
		cfee.custfeed();

		//employee feedback
		efee.empfeed();

		cout << endl;

		cout << endl;

		cout << " ************************** TRACKING ***************************" << endl;

		cout << endl;

		cout << " Do you want to track your order : (Y/N) : ";

		cin >> opt;

		if (opt == 'Y')
		{

			//calling tracker function
			tk.track();

		}

		else if (opt == 'N')
		{

			exit;

		}

		cout << endl;


		cout << "*********************** EMPLOYEE **************************" << endl;

		cout << endl;

		//calling login system
		L.username();
		L.password('p');
		L.ResetPass('r');

		//calling postalworker function
		pw.showpost();

		//calling clerk function
		c.calculate();

		//postman function
		p.post();

		//calling accountofficer funtion
		ac.calculate();

		//calling payment function
		py.show();

		//calling transaction record function
		tr.cal();

		//calling sorting function
		so.sort1();

		//calling postoffice function
		po.func();

		//calling gpo function
		g.showdetail2();

		//calling mail class function
		object.showdetails();

		//bounce mail function
		bl.show();

		//returnedmail function
		ri.function();


		cout << endl;



	}



	

	return 0;



}