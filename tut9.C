void tut9() //this function must be the same name as the filename
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
    hist->SetFillColor(kGreen-9); //-9 adjust clor intensity
    hist->GetXaxis()->SetTitle("Distribution");
    hist->GetYaxis()->SetTitle("Entries");

    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);

    TF1 *fit = new TF1("fit", "gaus", 0, 10);
    fit->SetLineWidth(4);
    //fit->SetLineColor(2); //sets line color. 2 is default color red
    fit->SetLineStyle(3); //sets line style. 2 is for dotted linestyle, 3 for dash line

    TCanvas *C1 = new TCanvas();
    C1->SetTicky();
    C1->SetGridx();
    C1->SetGridy();
    hist->SetStats(0); //to remove the statistics box on the upper right
    hist->Draw();
    hist->Fit("fit", "R"); //R FOR RANGE in line 33, FITTING WITHOUT USING THE FIT PANEL. Watch video 9 for more alternatives.
                          //RQ0 Q prevents statistics value to show in terminal , 0 removes the fit curve
    
    //next line is for adding legends
    TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
    leg->SetBorderSize(0); //this removes the border on the legend
    leg->AddEntry(hist, "Measured Data", "f");
    leg->AddEntry(fit, "Fit Function", "l");
    leg->Draw();   
    
    
    //next lines will pick mean and sigma values for further computation
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);

    cout << mean/sigma << endl;
}
// the "constant" in the output after fitting is the area under the curve