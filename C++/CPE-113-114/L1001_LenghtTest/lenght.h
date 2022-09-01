class Length
{
    public:
        Length();
        Length(int);
        Length(int, int);
        void setAll(int, int);
        void setKilometre(int);
        void setMetre(int);
        int getKilometre();
        int getMetre();
        int getTotalMetre();
        double getDecimal();
    private:
        int kilometre;
        int metre;
        void round();
};
