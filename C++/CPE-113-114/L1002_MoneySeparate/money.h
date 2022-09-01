class Money
{
    friend const Money operator+(int, const Money &);
    friend const Money operator*(double, const Money &);
    friend bool operator<(double, const Money &);

    public:
        Money() ;
        Money(int);
        Money(int, int);
        Money(double);

        void setBoth(int, int);
        void setDollars(int);
        void setCents(int);

        int getDollars() const;
        int getCents() const;

        double operator!() const;

        void output() const;

        const Money operator+(const Money &) const;
        const Money operator-(const Money &) const;

        bool operator<(const Money &) const;
        bool operator>(const Money &) const;
        bool operator==( const Money &) const;

        const Money operator*(double) const;
        const Money operator+=(const Money &);
        const Money operator/(double) const;
        const Money operator-=(const Money &);

        const Money operator++();
        const Money operator--();
        const Money operator++(int);
        const Money operator--(int);

        const Money operator+(int) const;
        bool operator<(double) const;

    private:
        int dollars;
        int cents;
};

const Money operator+(int, const Money &);
const Money operator*(double, const Money &);
bool operator<(double, const Money &);
