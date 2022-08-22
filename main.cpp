
//=================================================================================
// Name         : DS Assignment#4
// Author       :
// Version      : 1.0
// Date Created : Apr-17-2022
// Date Modified:
// Description  : Starter Code for Flight-Ticket Management System using HASH TABLE in C++
//=================================================================================
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<math.h>
#include<time.h>
#include<fstream>

using namespace std;

class Flight_Ticket
{
    private:
        string companyName;
        int flightNumber;
        string country_of_origin;
        string country_of_destination;
        string stopOver;
        string price;
        string time_of_departure;
        string time_of_arrival;
        string date;

    public:
        Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date)
    {
            this->companyName = companyName ;
            this->flightNumber = flightNumber;
            this->country_of_origin = country_of_origin;
            this->country_of_destination = country_of_destination;
            this->stopOver = stopOver;
            this->price = price;
            this->time_of_departure = time_of_departure;
            this->time_of_arrival = time_of_arrival;
            this->date = date;
    
    }
    
    Flight_Ticket()
    {
        
    }
    
    void displayTicket()
    {
        cout<<"companyName : "<<companyName;
        cout<<"\n  flightNumber : "<<flightNumber;
        cout<<"\n  country_of_origin : "<<country_of_origin<<"\n  country_of_destination : "<<country_of_destination;
        cout<<"\n  stopOver : "<<stopOver<<"\n  price : "<<price;
        cout<<"\n  time_of_departure : "<<time_of_departure;
        cout<<"\n  time_of_arrival : "<<time_of_arrival<<"\n  date : "<<date;
        
    }
    
    void displayTicketData()
    {
        cout<<companyName<<","<<flightNumber<<","<<country_of_origin<<","<<country_of_destination<<","<<stopOver<<","<<price<<","<<time_of_departure<<","<<time_of_arrival<<","<<date<<endl;
    }
    
    bool checkTicket( Flight_Ticket f)
    {
        return
        this->companyName == f.companyName &&
        this->flightNumber == f.flightNumber &&
        this->country_of_origin == f.country_of_origin &&
        this->country_of_destination == f.country_of_destination &&
        this->stopOver == f.stopOver &&
        this->price == f.price &&
        this->time_of_departure == f.time_of_departure &&
        this->time_of_arrival == f.time_of_arrival &&
        this->date == f.date;
        
    }
    
    bool checkDate(string date)
    {
        return this->date == date;
    }
    
    string getKey()
    {
        return companyName + to_string(flightNumber);
    }
    
    string getDestination()
    {
        return country_of_destination;
    }
    
    string getcompanyName()
    {
        return companyName;
    }
    int getflightNumber()
    {
        return flightNumber;
    }
    string getcountry_of_origin()
    {
        return country_of_origin;
    }
    string getcountry_of_destination()
    {
        return country_of_destination;
    }
    string getstopOver()
    {
        return stopOver;
    }
    string getprice()
    {
        return price;
    }
    string gettime_of_departure()
    {
        return time_of_departure;
    }
    string gettime_of_arrival()
    {
        return time_of_arrival;
    }
    string getdate()
    {
        return date;
    }

       
};
//=====================================
//=====================================

template<typename Elem>
class MyList
{
    private:
    
        struct Node
        {
            Elem elem;
            Node* prev;
            Node* next;
          
            Node ()
            {
                
            }
            Node(Elem e)
            {
                this->elem = e;
            }
        };
    
    public:
    
        class Iterator
        {
            public:
                Elem& operator*() { return v->elem; }
                bool operator==(const Iterator& p) const  { return v == p.v; }
                bool operator!=(const Iterator& p) const  { return v != p.v; }
                Iterator& operator++()
                {
                    v = v->next;
                    return *this;
                }
                Iterator& operator--()
                {
                   v = v->prev;
                   return *this;
                }
                friend class MyList;
            
            private:
                Node* v; // pointer to the node
                Iterator(Node* u) // constructor
                {
                   v = u;
                }
        };
    
    public:
    
        MyList()                               // default constructor
        {
            n = 0;
            header = new Node;
            trailer = new Node;
            header->next = trailer;
            trailer->prev = header;
        }
    
        int size() const        { return n; }                       // list size
        bool empty() const      { return (n == 0); }                // is the list empty?
        Iterator begin() const  { return Iterator(header->next); }      // beginning position
        Iterator end() const    { return Iterator(trailer); }           // (just beyond) last position
    
        void insertFront(const Elem& e);        // insert at front
    
        void insertBack(const Elem& e)          // insert at rear
        {
            Node* temp = new Node(e);
            Node* u = trailer->prev;
            u->next = temp;
            trailer->prev = temp;
            
            temp->prev = u;
            temp->next = trailer;
            
            n++;
            
        }
        void insert(const Iterator& p, const Elem& e) // insert e before p
        {
            Node* w = p.v; //w points to the node associated with p
            Node* u = w->prev;
            Node* v = new Node;
            v->elem = e;
            v->next = w; w->prev = v;
            v->prev = u; u->next = v;
            n++; //update the number of elements
            
        }
        void erase(const Iterator& p)          // remove p
        {
            Node* v = p.v;
            Node* w = v->next;
            Node* u = v->prev;
            u->next = w; w->prev = u;
            delete v;
            n--; //update the number of elements
        }
    
        void display()
        {
            int count = 1;
            for( Iterator i(begin()); i != end() ; ++i )
            {
                cout<<endl;
                cout<<count<<".";
                Elem t;
                t  = *i;
                t.displayNode();
               
                count++;
            }
        }
    
        bool checkDuplicate(Flight_Ticket* data)
        {
            if (!empty())
            for( Iterator i (begin()) ; i != end() ; ++i )
            {
                Elem t;
                t  = *i;
                
                if ( t.checkNode( *data) == true )
                {
                    return true;
                }
                
            }
            return false;
        }
    
       /* bool checkDuplicateKey(string key, Flight_Ticket f )
        {
            if (!empty())
            for( Iterator i (begin()) ; i != end() ; ++i )
            {
                Elem t;
                t  = *i;
                
                if ( t.checkKey(key) == true and t.checkNode(f) == false )
                {
                    return true;
                }
                
            }
            return false;
        }
        */
    
    
    private:
    
        int n;                                  // number of items
        Node* header;                           // head-of-list sentinel
        Node* trailer;                          // tail-of-list sentinel
};


//=====================================
//=====================================
class HashNode
{
    private:
        string key; // key = companyName+flightNumber
        Flight_Ticket value;
    public:
        HashNode(string key, Flight_Ticket value)
        {
            this->key = key;
            this->value = value;
        }
        HashNode()
        {
            
        }
        void displayNode()
        {
            value.displayTicket();
        }
    
        void displayNodeData()
        {
            value.displayTicketData();
        }
    
        bool checkNode( Flight_Ticket f)
        {
            return value.checkTicket( f );
        }
    
        bool checkNodeDate(string date)
        {
            return value.checkDate( date );
        }
    
        bool checkKey( string key )
        {
            return this->key == key;
        }
    
        Flight_Ticket getValue()
        {
            return this->value;
        }
    
        string getKey()
        {
            return this->key;
        }

        friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
    private:
        MyList<HashNode> *buckets;                //List of Buckets, Please create your own List Class called MyList
        int size;                        //Current Size of HashTable
        int capacity;                    // Total Capacity of HashTable
        int collisions;
        // add more attributes as needed
    public:
        FlightHASHTABLE();                        //constructor
        ~FlightHASHTABLE();                       //destructor
        long hashCode(string key);                       //implement and test different hash functions
        int importCSV(string path);            //Load all the flight-tickets from the CSV file to the HashTable
        int exportCSV(string path);            //Export all the flight-tickets from the HashTable to a CSV file in an ascending order
        int count_collisions();                //return the number of collisions on the HashTable
        int add(Flight_Ticket* data);          //add new flight to the HashTable
        void removeRecord (string companyName, int flightNumber);    //Delete a record with key from the hashtable
        void find(string companyName, int flightNumber);        //Find and Display records with same key entered
        void allinday(string date);                      //Find and Display records with same day entered
        void printASC(string companyName, int flightNumber);          //display the collisions for the entered key in an ascending order

        // add more methods as needed
};

//==========================================================

FlightHASHTABLE::FlightHASHTABLE()
{
    this->capacity = 125003;
    this->size = 0;
    this->collisions = 0;
    buckets = new MyList<HashNode>[capacity];      //Array of a list/chain
}

FlightHASHTABLE::~FlightHASHTABLE()
{
    delete[] buckets;
}

int FlightHASHTABLE::count_collisions()
{
   
    collisions = 0;
    
     for(int hcode = 0; hcode < capacity ; hcode++)
     {
         int listCollisions = 0;
         
         if(!buckets[hcode].empty() && buckets[hcode].size()!= 1)
          for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
          {
              HashNode t1;
              t1  = *i;
              
            
              int check = 0;
             
              for( MyList<HashNode>::Iterator j (buckets[hcode].begin()) ; j != i  ; ++j )
              {
                  HashNode t2;
                  t2  = *j;
                  string key = t2.getKey();
                  
                  if( t1.checkKey( key )   ==   true  )
                  {
                      check = 1;
                      
                  }
                  
                  
              }
              
              if(check == 0)
              {
                  listCollisions++;
              }
              
              
        }
         
         if(listCollisions == 0)
             collisions += listCollisions;
         
         else
             collisions += listCollisions - 1;
    }
    
    
    
    return collisions;
}


long FlightHASHTABLE::hashCode(string key)
{
    long hcode = 0;
    
    for(int i = 0 ; i < key.length() ; i++)
    {
        hcode = hcode * 31 + (long) (key[i])  ;
        
    }
    
    if(hcode < 0)
        hcode = hcode * -1;
    
    //makes sure it's not more than the capacity
    hcode %= capacity;
    
    return hcode;
    
}

/*
long FlightHASHTABLE::hashCode(string key)
{
    long hcode = 0;
 
    for (int i = 0; i < key.length(); i++)
   {
     hcode = (hcode << 5) | (hcode >> 27); // 5-bit cyclic shift of the running sum
     hcode += (long) key[i]; // add in next character
   }
    
    if(hcode < 0)
        hcode = hcode * -1;
    
    //makes sure it's not more than the capacity
    hcode %= capacity;
    
   return hcode;
}*/



/*
long FlightHASHTABLE::hashCode(string key)
{
    long hcode = 0;
    
    for(int i = 0 ; i < key.length() ; i++)
    {
        
        hcode += (long) (key[i]);
        
    }
    
    if (hcode < 0)
        hcode = hcode * -1;
    
    //makes sure it's not more than the capacity
    
    hcode %= capacity;
    
    return hcode;
    
}*/


int FlightHASHTABLE::add(Flight_Ticket* data)
{
    string key = data->getKey();
    
    HashNode tempNode = HashNode( key, *data );
    
    long hcode = hashCode(key);
    
    if ( buckets[hcode].checkDuplicate(data) == true)
    {
        cout<<"\nRecord already exists!";
        return 0;
    }
    
    else
    {
        
        buckets[hcode].insertBack(tempNode);
        
        size++;
        
        return 1;
    }
}

void FlightHASHTABLE::removeRecord (string companyName, int flightNumber)
{
    
    string key = companyName + to_string(flightNumber);
    
    long hcode = hashCode(key);
    
    int check =  0;
    int count = 1;
    
    for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
    {
        HashNode t;
        t  = *i;
        
        if (t.checkKey(key) == true)
        {
            check = 1;
            
            cout<<endl;
            cout<<count<<".";
            HashNode t = *i;
            t.displayNodeData();
           
            count++;
        }
    }
    
    string choice;
    
    cout<<"\nPlease select the record you want to delete: ";
    getline(cin,choice);
    
    count = 1;
    
    for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
    {
        HashNode t;
        t  = *i;
        
        if (t.checkKey(key) == true && stoi(choice) == count)
        {
            buckets[hcode].erase(i);
            cout<<"\nRecord deleted successfully!";
        }
        
        
        if (t.checkKey(key) == true)
        {
            count++;
        }
        
      
    }
    
    if (check == 0)
    {
        cout<<"\nRecord does not exist!";
    }

}


void FlightHASHTABLE::find(string companyName, int flightNumber)
{
   
    clock_t start, end;
      
        /* Recording the starting clock tick.*/
        start = clock();
    
    
    string key = companyName + to_string(flightNumber);
    
    long hcode = hashCode(key);
    
    int check =  0;
    int count = 1;
    

    
    for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
    {
        HashNode t;
        t  = *i;
        
        if (t.checkKey(key) == true)
        {
            check = 1;

            cout<<endl;
            cout<<count<<".";
            HashNode t = *i;
            t.displayNode();
            count++;
        }
    }

    if (check == 0)
    {
        cout<<"\nRecord does not exist!";
    }
    
    
    // Recording the end clock tick.
        end = clock();
      
        // Calculating total time taken by the program.
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed
             << time_taken << setprecision(5);
        cout << " sec " << endl;

    
}

void FlightHASHTABLE::allinday(string date)
{

    int check =  0;
    int count = 1;
    
    for(int hcode = 0; hcode < capacity ; hcode++)
    {
        if(!buckets[hcode].empty())
        for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
        {
            
            HashNode t;
            t  = *i;
            
            
            if (t.checkNodeDate(date))
            {
                check = 1;

                cout<<endl;
                cout<<count<<".";
                HashNode t = *i;
                t.displayNodeData();
                count++;
            }
        }
        
    }
    if (check == 0)
    {
        cout<<"\nRecord does not exist!";
    }
    
}

void FlightHASHTABLE::printASC(string companyName, int flightNumber)
{
    string key = companyName + to_string(flightNumber);
    
    long hcode = hashCode(key);
    
    int check =  0;
    int count = 0;
    
    for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
    {
        HashNode t;
        t  = *i;
        
        if (t.checkKey(key) == true)
        {
            check = 1;
            count++;
        }
    }
    
    
    if (check == 0)
    {
        cout<<"\nRecord does not exist!";
        return;
    }
    
    Flight_Ticket * array = new Flight_Ticket[count];
    
    int n  = 0;
       
    for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
    {
        HashNode t;
        t  = *i;
        
        if (t.checkKey(key) == true)
        {
            array[n] = t.getValue();
            n++;
        }
    }
    
    for (int i = 0 ; i < count - 1 ; i ++)
        for (int j = 0 ; j < count - i  - 1; j++)
        {
            if( array[j].getDestination() > array[j+1].getDestination())
                swap(array[j],array[j+1]);
        }
    
    n = 1 ;
    
    for(int i = 0; i < count ; i++)
    {
        cout<<endl;
        cout<<n<<".";
        array[i].displayTicketData();
        n++;
    }
        
            
}

int FlightHASHTABLE::importCSV(string path)
{
    ifstream f1;
    string x;
    //maintaining the contacts imported
    int count = 0;
    
    //opening the file
    f1.open(path, ios::in);

    //while the file does not end
    while( getline(f1,x) )
    {
        
        string companyName = "";
        string flightNumber = "";
        string country_of_origin = "";
        string country_of_destination = "";
        string stopOver = "";
        string price = "";
        string time_of_departure = "";
        string time_of_arrival = "";
        string date = "";
        
        int check = 0;
        int checkQuote = 0;
        
        // x.length() is the length of the line
        for ( int i = 0 ; i< x.length() ; i++)
            
        {
            if ( check == 0 && x[i] != ',' )
            {
                companyName += x[i];
            }
            
            else if ( check == 1 && x[i] != ',' )
            {
                flightNumber += x[i];
            }
            
            else if ( ( check == 2 && x[i] != ','  )  || (check == 2 && checkQuote == 1) )
            {
                if (x[i] == '"' && checkQuote == 0)
                    checkQuote = 1;
                
                else if (x[i] == '"' && checkQuote == 1)
                    checkQuote = 0;
                
                country_of_origin += x[i];
            }
            
            else if ( ( check == 3 && x[i] != ',' ) || ( check == 3 && checkQuote == 1 ) )
            {
                if (x[i] == '"' && checkQuote == 0)
                    checkQuote = 1;
                
                else if (x[i] == '"' && checkQuote == 1)
                    checkQuote = 0;
                
                country_of_destination += x[i];
            }
            
            else if ( check == 4 && x[i] != ',' )
            {
                stopOver += x[i];
            }
            
            else if ( check == 5 && x[i] != ',' )
            {
                price += x[i];
            }
            
            else if ( check == 6 && x[i] != ',' )
            {
                time_of_departure += x[i];
            }
            
            else if ( check == 7 && x[i] != ',' )
            {
                time_of_arrival += x[i];
            }
            
            else if ( check == 8 && x[i] != ',' )
            {
                date += x[i];
                
                // -2 as the last x[i] is endl
                if( i == x.length() - 2)
                    check = 9;
            }
            
            
            if ( check == 9 && x[i] != ',')
            {
                
                
                if(count != 0)
                {
                
                    Flight_Ticket * data = new Flight_Ticket( companyName, stoi(flightNumber), country_of_origin , country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date);
                
                    add(data);
                    
                }
                //check is made 0 for reading the next line
                check = 0;
                
                //increases the count since a contact has been added
                count++;
                
            }
            
            //check increases everytime a comma comes across
            if (x[i] == ',' && checkQuote == 0 )
                check++;
                
        }
        
    }
    
    //closes the file
    f1.close();
    
    if (count - 1 == 0)
        return -1;
    
    //count is returned (count -1 since the first line was skipped)
    else
        return count - 1;
    
    return -1;
}

int FlightHASHTABLE::exportCSV(string path)
{
    ofstream f1;
    
    f1.open(path, ios::app);
    
    int count = 0;
    
    for(int hcode = 0; hcode < capacity ; hcode++)
    {
        if( ! buckets[hcode].empty() )
        for( MyList<HashNode>::Iterator i (buckets[hcode].begin()) ; i != buckets[hcode].end() ; ++i )
        {
            count++;
            
            HashNode t;
            t  = *i;
            f1<<t.getValue().getcompanyName()<<","<<t.getValue().getflightNumber()<<","<<t.getValue().getcountry_of_origin()<<","<<t.getValue().getcountry_of_destination()<<","<<t.getValue().getstopOver()<<","<<t.getValue().getprice()<<","<<t.getValue().gettime_of_departure()<<","<<t.getValue().gettime_of_arrival()<<","<<t.getValue().getdate()<<endl;
        }
        
    }
    
    f1.close();
    
    if ( count != 0 )
        return count;
    else
        return -1;
}

//==========================================================
//==========================================================
void listCommands()
{
    cout<<"\n----------------------------------"<<endl;
    cout<<"import <path>          :Import flight-tickets from a CSV file"<<endl
        <<"export <path>          :Export flight-tickets to a CSV file"<<endl
        <<"count_collisions       :Print number of collisions"<<endl
        <<"add                    :Add a new flight-ticket"<<endl
        <<"delete <key>           :Delete a flight-ticket"<<endl
        <<"find <key>             :Find a flight-ticket's details"<<endl
        <<"allinday <date>        :Display all flight-tickets in a day"<<endl
        <<"printASC <key>         :Print flight-tickets in ascending order"<<endl
        <<"exit                   :Exit the program"<<endl;
}
//==========================================================

// to be completed with all the necessary method definitions

//==========================================================
int main(void)
{
    FlightHASHTABLE myFlightHASHTABLE;
    string user_input;
    string command;
    string key;

   
    while(true)
    {
        listCommands();
        cout<<">";
            
        getline(cin,user_input);

        // parse userinput into command and parameter(s)
        stringstream sstr(user_input);
        getline(sstr,command,' ');
        getline(sstr,key);
            
        if (command == "import")
        {
            int count = myFlightHASHTABLE.importCSV(key);
            cout<<endl<<endl<<count<<" flight-tickets imported!";
        }
        
        else if (command == "export")
        {
            ofstream f1;
            //to overwrite the old data in the file
            f1.open(key, ios::out);

            //number of flight tickets exported are displayed
            int count = myFlightHASHTABLE.exportCSV( key );
            cout<<endl<<endl<<count<<" flight-tickets exported!";

        }
        
        else if (command == "add")
        {
            string companyName;
            string flightNumber;
            string country_of_origin;
            string country_of_destination;
            string stopOver;
            string price;
            string time_of_departure;
            string time_of_arrival;
            string date;

            cout<<"\n enter details : ";
            getline(cin,companyName);
            getline(cin,flightNumber);
            getline(cin,country_of_origin);
            getline(cin,country_of_destination);
            getline(cin,stopOver);
            getline(cin,price);
            getline(cin,time_of_departure);
            getline(cin,time_of_arrival);
            getline(cin,date);
            
            Flight_Ticket * data = new Flight_Ticket( companyName, stoi(flightNumber), country_of_origin , country_of_destination, stopOver, price, time_of_departure, time_of_arrival, date);
            
            if ( myFlightHASHTABLE.add(data) == 1)
                cout<<"\nRecord added successfully!";

        }
        
        else if (command == "delete")
        {
            int check = 0;
            
            string companyName = "" , flightNumber = "";
            int fNumber = 0;
            
            for(int i = 0 ; i < key.length() ; i++)
            {
                if (check == 0 && key[i]!= ',')
                {
                    companyName += key[i];
                }
                
                if (key[i]==',')
                {
                    check = 1;
                }
                
                if(key[i] != ',' && check ==1)
                    flightNumber += key[i];
                
            }
            
            for (int i = 0; i< flightNumber.length(); i++)
            {
                fNumber += ( (int)flightNumber[i] -48 ) * pow( 10 , flightNumber.length() -1 - i);
            }
            
            myFlightHASHTABLE.removeRecord( companyName, fNumber);
            
        }
        
        else if (command == "find")
        {
            int check = 0;
            
            string companyName = "" , flightNumber = "";
            int fNumber = 0;
            
            for(int i = 0 ; i < key.length() ; i++)
            {
                if (check == 0 && key[i]!= ',')
                {
                    companyName += key[i];
                }
                
                if (key[i]==',')
                {
                    check = 1;
                }
                
                if(key[i] != ',' && check ==1)
                    flightNumber += key[i];
                
            }
            
            for (int i = 0; i< flightNumber.length(); i++)
            {
                fNumber += ( (int)flightNumber[i] -48 ) * pow( 10 , flightNumber.length() -1 - i);
            }
            
            myFlightHASHTABLE.find( companyName, fNumber);
            
        }
        
        else if (command == "allinday")
        {
            myFlightHASHTABLE.allinday ( key );
        }
        
        
        else if (command == "printASC")
        {
            int check = 0;
            
            string companyName = "" , flightNumber = "";
            int fNumber = 0;
            
            for(int i = 0 ; i < key.length() ; i++)
            {
                if (check == 0 && key[i]!= ',')
                {
                    companyName += key[i];
                }
                
                if (key[i]==',')
                {
                    check = 1;
                }
                
                if(key[i] != ',' && check ==1)
                    flightNumber += key[i];
                
            }
            
            for (int i = 0; i< flightNumber.length(); i++)
            {
                fNumber += ( (int)flightNumber[i] -48 ) * pow( 10 , flightNumber.length() -1 - i);
            }
            
            myFlightHASHTABLE.printASC( companyName, fNumber);
            
        }
        
        else if (command == "count_collisions")
        {
            cout<<"\nTotal number of collisions is "<<myFlightHASHTABLE.count_collisions();
        }
        
        else if( user_input == "exit" )
            exit(0);
        
        else
            cout<<"\nInvalid Command!";
            
            

    }

    return 0;
}
