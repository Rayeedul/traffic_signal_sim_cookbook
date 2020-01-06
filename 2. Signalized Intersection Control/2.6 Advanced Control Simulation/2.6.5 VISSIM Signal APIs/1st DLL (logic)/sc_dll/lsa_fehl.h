/*==========================================================================*/
/*  LSA_FEHL.H                                       Teil von ????????/SIM  */
/*                                                                          */
/*  Dieses Modul nimmt von allen anderen Modulen Fehlermeldungen entgegen   */
/*  und sorgt fuer ihre Ausgabe.                                            */
/*                                                                          */
/*  Version von 2004-05-11                                  Lukas Kautzsch  */
/*==========================================================================*/

#ifndef __LSA_FEHL_H
#define __LSA_FEHL_H

/*--------------------------------------------------------------------------*/

#define NO_PROCESS_ID 0

typedef  enum { Okay, Abbruch } FehlerStatusTyp;

extern  FehlerStatusTyp  FehlerStatus;
extern  char             errorfile_name [255];
extern  char             res_string [255];

/*--------------------------------------------------------------------------*/

char  *HoleRessourcenString (int str_id, char *buffer, int buffer_size);

/* Holt aus den Ressourcen des Programms den String mit der Nummer */
/* <str_id> und schreibt ihn in den Puffer <*buffer> der Laenge    */
/* <buffer_size>. Zurueckgegeben wird im Fehlerfall NULL, sonst    */
/* <buffer>.                                                       */

/*--------------------------------------------------------------------------*/

void  DateiMeldung (char *string);

/* Schreibt die Meldung <string> in die Fehlerdatei (LSAxy.ERR) */
/* und oeffnet letztere dafuer gegebenenfalls.                  */

/*--------------------------------------------------------------------------*/

void  BildschirmMeldung (char *string);

/* Gibt die Meldung <string> aus: Unter Windows in einer Messagebox, */
/* unter UNIX nach stderr.                                           */

/*--------------------------------------------------------------------------*/

void  AllgemeinerFehler (char *absender, char *grund);

/* Bildschirmmeldung "Allgemeiner Fehler" mit "Funktion: <absender>" */
/* und "Grund: <grund>"; <FehlerStatus> wird auf Abbruch gesetzt.    */

/*--------------------------------------------------------------------------*/

void  InternerFehler (const char *absender, const char *grund);

/* Bildschirmmeldung "Interner Fehler" mit "Funktion: <absender>" */
/* und "Grund: <grund>"; <FehlerStatus> wird auf Abbruch gesetzt. */

/*--------------------------------------------------------------------------*/

#define  SGPNR_UNZULAESSIG       1
#define  SGPNR_UNBEKANNT         2
#define  DETNR_UNZULAESSIG       3
#define  DETNR_UNBEKANNT         4

void  Laufzeitfehler (int fehlernr, char *prozedurname, unsigned nr);

/* Dateimeldung "Laufzeitfehler" mit <prozedurname> und Klartext fuer die */
/* Fehlernummer <fehlernr> sowie ggf. einer Zusatzinformation (<nr>).     */

/*--------------------------------------------------------------------------*/

void  ExitLSAFehler (void);

/* Schliesst die Fehlerdatei des Steuerungsprogramms, falls sie geoeffnet */
/* war, und gibt in diesem Fall auch eine Meldungsbox aus.                */

/*--------------------------------------------------------------------------*/

void SetConsoleMode (bool consoleMode);

/* Wenn <consoleMode> TRUE ist, dann werden alle           */
/* Nachrichten in die Datei ausgegeben, andernfalls        */
/* in einer Dialogbox.                                     */
/*                                                         */
/* Whether messages should be passed to the file or to     */
/* the GUI.                                                */

/*--------------------------------------------------------------------------*/

void SetSimulationCanceled(bool isCanceled);

/* Wenn <isCanceled> TRUE ist, dann wurde die aktuelle     */
/* Simulation abgebrochen.                                 */
/*                                                         */
/* Wether the simulation was canceled or not.              */

/*--------------------------------------------------------------------------*/

void SetProcessId (int processId);
/* Die Prozess Id wird ausschlie�lich in der Parallel-     */
/* version gesetzt. Ansonsten ist sie immer NO_PROCESS_ID. */
/*                                                         */
/* The process id is only set, if VISSIM was started in    */
/* parallel version. Otherwise the process id is always    */
/* NO_PROCESS_ID.                                          */

/*--------------------------------------------------------------------------*/

int GetProcessId(void);
/* Gibt die Prozess Id zur�ck.                             */
/* Die Prozess Id wird ausschlie�lich in der Parallel-     */
/* version gesetzt. Ansonsten ist sie immer NO_PROCESS_ID. */
/*                                                         */
/* Gets the process id.                                    */
/* The process id is only set, if VISSIM was started in    */
/* parallel version. Otherwise the process id is always    */
/* NO_PROCESS_ID.                                          */

/*--------------------------------------------------------------------------*/

bool IstConsoleModus (void);
/* Gibt zur�ck, ob VISSIM in einer interaktiven oder einer */
/* nicht interaktiven Version gestartet wurde.             */
/*                                                         */
/* Returns whether VISSIM is started in a non interactive  */
/* version.                                                */

/*--------------------------------------------------------------------------*/

bool IstSimulationAbgebrochen (void);
/* Gibt zur�ck, ob die Simulation in VISSIM vorzeitig      */
/* abgebrochen wurde.                                      */

#endif  /* __LSA_FEHL_H */

/*==========================================================================*/
/*  Ende von LSA_FEHL.H                                                     */
/*==========================================================================*/

