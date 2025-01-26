void tut1() //this function must be the same name as the filename
{
    TH1F *hist = new TH1F("hist", "Titile Histogram", 100, 0, 100); 

    hist->Fill(10);
    hist->Fill(90);

    hist->GetXaxis()->SetTitle("X Axis");
    hist->GetYaxis()->SetTitle("Y Axis");

    TCanvas *C1 = new TCanvas();
    hist->Draw();
}