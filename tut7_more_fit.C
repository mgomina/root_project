void tut7_more_fit() //this function must be the same name as the filename
{ //this tutorial is for doing Gaussian fit by codes and not using the fit panel.
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 10); //100 bins

    TRandom2 *rand = new TRandom2(3); //(3) is the chosen seed for this

    fstream file;
    file.open("data.txt", ios::out);

    for(int i = 0; i < 1000; i++)
    {
        double r = rand->Gaus(5,1); //(5, 1) 5 is the mean value, 1 is the standard deviation (sigma)
        file << r << endl; 
    }

    file.close(); //closes the file

                //fstream file; //c++ code to open file
    file.open("data.txt", ios::in); // opens the file again

    double value;

    while(1)
    {
        file >> value;
        hist->Fill(value);
        if(file.eof()) break;
    }
    
    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");

    TF1 *fit = new TF1("fit", "gaus", 4, 6);

    TCanvas *C1 = new TCanvas();
    hist->Draw();
    hist->Fit("fit", "R"); //R FOR RANGE in line 33, FITTING WITHOUT USING THE FIT PANEL. Watch video 9 for more alternatives.
                          //RQ0 Q prevents statistics value to show in terminal , 0 removes the fit curve
    //next lines will pick mean and sigma values for further computation
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);

    cout << mean/sigma << endl;
}
// the "constant" in the output after fitting is the area under the curve