#include <iostream>

using namespace std;

class Thing
{
    friend void make(Thing &, const Thing&);
    public:
        Thing() { }
        Thing(int d) : mv(d) { }
        void set(int d) { mv = d; };
        int get() const { return (mv); }
    private:
        int mv;
};

void make(Thing &, const Thing &);

int main()
{
    Thing t1(7), t2;
    make(t2, t1);
    cout << t2.get() << endl; return 0;
}

void make(Thing &to, const Thing &from)
{
    //to.set( from.get()*2 );
    to.mv = from.mv*2;
}
