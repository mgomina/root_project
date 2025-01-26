void tut2()
{
    double x[5] = {1,2,3,4,5}; //[5] sets the no. of data points
    double y[5] = {1,4,9,16,25};

    TGraph *gr = new TGraph(5, x, y); //constructs the graph and the entries

    gr->SetMarkerStyle(kFullCircle); //sets the coordinate style
    gr->SetMarkerSize(2);

    TCanvas *C1 = new TCanvas();
    gr->Draw("ALP"); //AL to draw a line while p sets the point
}