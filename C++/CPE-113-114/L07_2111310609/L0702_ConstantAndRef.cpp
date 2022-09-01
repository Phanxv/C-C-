#include <iostream>

using namespace std;
class Thing
{
public:
    Thing() : var(999) { /*var = 999*/ }
    int var;

    void in();
    void out() const;
};
void out(Thing t)
{
    cout << t.var << ' ';
}
void Thing::in()
{
    cin >> var;
}
void Thing::out()const
{
    cout << var << ' ';
}
int main()
{
    Thing o;
    Thing &r = o;
    const Thing &cr = o;

    o.var = 777;
    out(o); out(r); out(cr);

    r.var = 222;
    out(o); out(r); out(cr);

    //cr.var = 444;

    o.in(); r.in();
    //cr.in();
    o.out(); r.out();
    cr.out();

    Thing().in();
    return 0;
}