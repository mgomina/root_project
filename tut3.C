void tut3() //this function must be the same name as the filename
{ //this tutorial is for reading input file (data.txt)
    TH1F *hist = new TH1F("hist", "Histogram", 6, 1, 7); //6 bins since max frequency is 5, 1 is min grade, 7 limit for n+1 bins

    fstream file; //c++ code to open file
    file.open("data.txt", ios::in);

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
}