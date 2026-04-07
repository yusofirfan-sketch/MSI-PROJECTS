(* Lab 4 – LED Control with Push Buttons *)

VAR
    Btn_On: BOOL;    (* Push button to turn LED on *)
    Btn_Off: BOOL;   (* Push button to turn LED off *)
    LED: BOOL;       (* LED output *)
END_VAR

(* Logic: LED turns on when Btn_On pressed, off when Btn_Off pressed *)

IF Btn_On THEN
    LED := TRUE;
ELSIF Btn_Off THEN
    LED := FALSE;
END_IF;
