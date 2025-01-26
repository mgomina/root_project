void tut5() //for generating random numbers
{
    TRandom2 *rand = new TRandom2(1); //using (0) allows random numbers for different runs, unlike (), (1), (2)

    TH1F *hist = new TH1F("hist", "Histogram", 25, 0, 100);

    for (int i=0; i<10000; i++) //generates n [i<n;] random numbers between 0 and 1 
    {
        double r = rand->Rndm()*100;
        cout << r << endl;
        hist->Fill(r);
    }

    TCanvas *C1 = new TCanvas();
    hist->GetYaxis()->SetRangeUser(0,1000);
    hist->Draw();
}