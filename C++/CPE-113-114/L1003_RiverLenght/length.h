#ifndef LENGTH_H
#define LENGTH_H
class Length
{
    public:
        Length();
        Length(int);
        Length(int, int);
        void set(int, int);
        void setKilometre(int);
        void setMetre(int);
        int getKilometre();
        int getMetre();
        double getDecimal();
        bool operator<(Length);
        bool operator>(Length);
        bool operator==(Length);
        bool operator!=(Length);
        Length operator+(Length);
        Length operator-(Length);
    private:
        int kilometre;
        int metre;
        void adjust();
};
#endif // LENGTH_H
