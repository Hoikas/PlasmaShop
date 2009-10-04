#ifndef _QPLASMATEXTDOC_H
#define _QPLASMATEXTDOC_H

#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerfni.h>
#include <Qsci/qscilexerfx.h>
#include <Qsci/qscilexerhexisle.h>
#include <Qsci/qscilexerproperties.h>
#include <Qsci/qscilexerpython.h>
#include <Qsci/qscilexersdl.h>
#include <Qsci/qscilexerxml.h>
#include "QPlasmaDocument.h"

class QPlasmaTextDoc : public QPlasmaDocument {
    Q_OBJECT

public:
    enum SyntaxMode {
        kStxNone, kStxPython, kStxSDL, kStxIni, kStxConsole, kStxXML,
        kStxHex, kStxFX,
    };

    enum EncryptionMode {
        kEncNone, kEncXtea, kEncAes, kEncDroid,
    };

    enum EncodingMode {
        kTypeAnsi, kTypeUTF8, kTypeUTF16, kTypeUTF32,
    };

    QPlasmaTextDoc(QWidget* parent);

    virtual void loadFile(QString filename);
    virtual void saveTo(QString filename);

    void setSyntax(SyntaxMode syn);
    void setEncryption(EncryptionMode enc);
    void setEncoding(EncodingMode type);

    SyntaxMode syntax() const;
    EncryptionMode encryption() const;
    EncodingMode encoding() const;

private:
    QsciScintilla* fEditor;
    SyntaxMode fSyntax;
    EncryptionMode fEncryption;
    EncodingMode fEncoding;

    QsciLexerFni* fLexerFNI;
    QsciLexerFX* fLexerFX;
    QsciLexerHexIsle* fLexerHEX;
    QsciLexerProperties* fLexerINI;
    QsciLexerPython* fLexerPY;
    QsciLexerSDL* fLexerSDL;
    QsciLexerXML* fLexerXML;

private slots:
    void adjustLineNumbers();
};

#endif
