void tut10()
{
    TCanvas *C1 = new TCanvas();

    TGraphErrors *gr = new TGraphErrors();

    fstream file; //file function
    file.open("data3.txt", ios::in); //opens file, in is for reading the valus

    double x, y, ex, ey; // to be read from the file

    int n = 0; 

    while(1) //1 means all lines in the file
    {
        file >> x >> y >> ex >> ey; // follows the format in the txt file

        n = gr->GetN(); //takes data points starting from 0 as defined in line 12

        gr->SetPoint(n, x, y);
        gr->SetPointError(n, ex, ey);

        if(file.eof()) break;

    }

    gr->Draw("A*");

    TF1 *fit = new TF1("fit", "pol1");
    gr->Fit("fit");
}