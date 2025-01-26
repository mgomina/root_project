void tut4()
{
    TGraph *gr = new TGraph(); //defines empty graph, entries will be defined by while loop to read from file data2.txt

    gr->SetMarkerStyle(kFullCircle); //sets the coordinate style
    gr->SetMarkerSize(2);
    gr->SetMarkerColor(kBlue);
    gr->SetLineWidth(2);
    gr->SetLineColor(kRed);

    gr->SetTitle("Graph");
    gr->GetXaxis()->SetTitle("X values");
    gr->GetYaxis()->SetTitle("Y values");

    fstream file;
    file.open("data2.txt", ios::in);
    while (1)
    {
        double x, y;
        file >>x >> y;
        gr->SetPoint(gr->GetN(), x, y);
        if(file.eof()) break;
    }
    
    file.close();

    TCanvas *C1 = new TCanvas();
    gr->Draw("ALP"); //AL to draw a line while p sets the point
}