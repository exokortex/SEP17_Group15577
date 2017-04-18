//------------------------------------------------------------------------------
// HTMLWriter.h
//
// Group: Group 15577, study assistant Roman Walch
//
// Authors: Johannes Haring 1611655
//          Thomas Moder 1615103
//          Verena Buder 1312723
//------------------------------------------------------------------------------
//

#ifndef HTMLWRITER_H_INCLUDED
#define HTMLWRITER_H_INCLUDED

//------------------------------------------------------------------------------
// class HTMLWriter
// implements the methods and attributes
//
class HTMLWriter
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    // setzt den Default-Dateinamen für die Ausgabe
    //
    HTMLWriter(string filename = basisHTML);

    //--------------------------------------------------------------------------
    // Methode
    //
    void writeFile(const char* file, int argc, char *argv[])
	{
      ofstream file;
      file.open("basisHTML.html");

      file.PutString("<html lang="en">\n");
      file.PutString("<head>\n");
      file.PutString("<meta charset="utf-8">\n");
      file.PutString("<meta http-equiv="refresh" content="3">\n");
      file.PutString("<title>SEP 2017</title>\n");
      file.PutString("<style>boy{margin: 0px; padding: 0px;}</style>\n");
      file.PutString("</head>\n");
      file.PutString("<body></body>\n");
      file.PutString("</html>\n");
    }

    {
      ifstream file;
      string s;
      file.open(argv[1], ios::in);
      while (!file.eof())
      {
	    getline(file, string);
	    file << string << endl;
      }
    file.close();
    }
	return File;

private:

  string filename_; //Attribut



};

#endif /* HTMLWRITER_H_INCLUDED */
