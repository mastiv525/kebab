#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/filefn.h> 



class MyApp : public wxApp {

public:

	wxStaticText * Miesko, * Otoczka, *Sosiki;

	wxRadioButton * Wołowina, *Kurczak, *Wege, *Baran, *Bułka, *Rollo, *Box, *Talerz;
	
	wxCheckBox *Łagodny, *Ostry, *Ziołowy, *Czosnkowy, *Killer, *Mieszany;

	int cena = 0;

	virtual bool OnInit() override {
		auto window = new wxFrame(nullptr, wxID_ANY, "Najlepszy kebab w mieście", wxPoint(-1, -1));
		window->SetSize(500, 500);
		window->SetBackgroundColour(wxColour("yellow"));

		Miesko = new wxStaticText(window, wxID_ANY, "Jakie chcesz mięsko :");
		Miesko->SetPosition(wxPoint(20, 20));

		Wołowina = new wxRadioButton(window, wxID_ANY, "Wołowina", wxPoint(10, 50), wxDefaultSize, wxRB_GROUP);

		Kurczak = new wxRadioButton(window, wxID_ANY, "Kurczak", wxPoint(10, 100), wxDefaultSize, 0);

		Wege = new wxRadioButton(window, wxID_ANY, "Wege", wxPoint(10, 150), wxDefaultSize, 0);

		Baran = new wxRadioButton(window, wxID_ANY, "Wege", wxPoint(10, 200), wxDefaultSize, 0);

		Otoczka = new wxStaticText(window, wxID_ANY, "Co dookoła :");
		Otoczka->SetPosition(wxPoint(200, 10));

		Bułka = new wxRadioButton(window, wxID_ANY, "Bułka", wxPoint(200, 50), wxDefaultSize, wxRB_GROUP);

		Rollo = new wxRadioButton(window, wxID_ANY, "Rollo", wxPoint(200, 100), wxDefaultSize, 1);

		Talerz = new wxRadioButton(window, wxID_ANY, "Box", wxPoint(200, 150), wxDefaultSize, 1);

		Box = new wxRadioButton(window, wxID_ANY, "Box", wxPoint(200, 200), wxDefaultSize, 1);

		Sosiki = new wxStaticText(window, wxID_ANY, "Jakie sosiki :");
		Sosiki->SetPosition(wxPoint(400, 10));

		Łagodny = new wxCheckBox(window, wxID_ANY, "Łagodny", wxPoint(400, 50), wxDefaultSize, wxCHK_2STATE);

		Ostry = new wxCheckBox(window, wxID_ANY, "Ostry", wxPoint(400, 100), wxDefaultSize, wxCHK_2STATE);

		Ziołowy = new wxCheckBox(window, wxID_ANY, "Ziołowy", wxPoint(400, 150), wxDefaultSize, wxCHK_2STATE);

		Czosnkowy = new wxCheckBox(window, wxID_ANY, "Czosnkowy", wxPoint(400, 200), wxDefaultSize, wxCHK_2STATE);

		Killer = new wxCheckBox(window, wxID_ANY, "Killer", wxPoint(400, 250), wxDefaultSize, wxCHK_2STATE);

		Mieszany = new wxCheckBox(window, wxID_ANY, "Mieszany(zawiera wszystkie)", wxPoint(400, 300), wxDefaultSize, wxCHK_2STATE);

		auto button = new wxButton(window, wxID_ANY, "Cena", wxPoint(300, 250), wxSize(80, 20));
		button->Bind(wxEVT_BUTTON, &MyApp::cena, this);
		window->Show(true);


		return true;
	}
	void cena(wxCommandEvent&) {



		if (Wołowina->GetValue() == true) {
			cena = cena + 12;
		}
		else if (Kurczak->GetValue() == true) {
			cena = cena + 10;
		}
		else if (Baran->GetValue() == true) {
			cena = cena + 10;
		}
		else if (Wege->GetValue() == true) {
			cena = cena + 8;
		}
		else {
			cena = cena;
		}

		if (Bułka->GetValue() == true) {
			cena = cena + 4;
		}
		else if (Rollo->GetValue() == true) {
			cena = cena + 2;
		}
		else if (Talerz->GetValue() == true) {
			cena = cena + 1,5;
		}
		else if (Box->GetValue() == true) {
			cena = cena + 1;
		}
		else {
			cena = cena;
		}

		if (Łagodny->GetValue() == true) {
			cena = cena + 2;
		}
		else {
			cena = cena;
		}

		if (Ostry->GetValue() == true) {
			cena = cena + 2;
		}
		else {
			cena = cena;
		}

		if (Ziołowy->GetValue() == true) {
			cena = cena + 2;
		}
		else {
			cena = cena;
		}

		if (Czosnkowy->GetValue() == true) {
			cena = cena + 2;
		}
		else {
			cena = cena;
		}

		if (Killer->GetValue() == true) {
			cena = cena + 5;
		}
		else {
			cena = cena;
		}

		if (Mieszany->GetValue() == true) {
			cena = cena + 13;
		}
		else {
			cena = cena;
		}

	


	}

};

wxIMPLEMENT_APP(MyApp);