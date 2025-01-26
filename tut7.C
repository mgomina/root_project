void tut7() //this function must be the same name as the filename
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
    
    hist->GetXaxis()->SetTitle("Grade");
    hist->GetYaxis()->SetTitle("Entries");

    TCanvas *C1 = new TCanvas();
    hist->Draw();
    hist->Fit("gaus"); //FOR AUTO FITTING WITHOUT USING THE FIT PANEL. Watch video 9 for more alternatives.
}
// the "constant" in the output after fitting is the area under the curve