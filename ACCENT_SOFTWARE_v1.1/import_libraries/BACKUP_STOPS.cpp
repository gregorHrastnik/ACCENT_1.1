//
//
//#ifdef pokazi
//
//
//
//
/////MALI IGRALNIK rodgers pazi pri drugem za eno plato zamaknjeno
//#ifdef _ANGELINA
//Stops stop0(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);//dodaj na konec odvisno kako je prva zamaknjena
//Stops stop1(0, 1, MIDI_2, MIDI_PORT_1, MANUAL_1, "BORDUN16", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop2(1, 2, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop3(2, 3, MIDI_2, MIDI_PORT_1, MANUAL_1, "FLUTE HARMONIQ", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop4(3, 4, MIDI_2, MIDI_PORT_1, MANUAL_1, "SALICIONAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop5(4, 5, MIDI_2, MIDI_PORT_1, MANUAL_1, "OKTAVE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop6(5, 6, MIDI_2, MIDI_PORT_1, MANUAL_1, "SPITZFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop7(6, 7, MIDI_2, MIDI_PORT_1, MANUAL_1, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop8(7, 8, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL 2", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop9(8, 9, MIDI_2, MIDI_PORT_1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop10(9, 5, MIDI_2, MIDI_PORT_2, MANUAL_1, "TROMPETE 8", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop11(10, 11, MIDI_2, MIDI_PORT_1, MANUAL_1, "CLARION", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop12(I_PED, 0, 0, 0, 0, "I-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop13(SUB_I, 0, 0, 0, 0, "SUB I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop14(SUPER_I, 0, 0, 0, 0, "SUPER I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop15(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop16(11, 12, MIDI_2, MIDI_PORT_1, MANUAL_2, "BORDUN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop17(12, 13, MIDI_2, MIDI_PORT_1, MANUAL_2, "PRESTANT", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop18(13, 14, MIDI_2, MIDI_PORT_1, MANUAL_2, "ROHRFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop19(14, 15, MIDI_2, MIDI_PORT_1, MANUAL_2, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop20(15, 16, MIDI_2, MIDI_PORT_1, MANUAL_2, "GEMSHORN", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop21(16, 1, MIDI_2, MIDI_PORT_2, MANUAL_2, "TERZE", "1 3/5''", &on_stop_ON, &on_stop_OFF);
//Stops stop22(17, 2, MIDI_2, MIDI_PORT_2, MANUAL_2, "PICCOLO", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop23(18, 3, MIDI_2, MIDI_PORT_2, MANUAL_2, "SCHARF 3F.", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop24(19, 4, MIDI_2, MIDI_PORT_2, MANUAL_2, "KRUMMHORN", "8'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop25(NULL_address, 0, 0, 0, MANUAL_2, "TREMULANT", "manual I", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//
//Stops stop26(NULL_address, II_I, 0, 0, 0, "II-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop27(NULL_address, II_PED, 0, 0, 0, "II-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop28(SUB_II, 0, 0, 0, 0, "SUB II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop29(SUPER_II, 0, 0, 0, 0, "SUPER II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop30(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop31(20, 14, MIDI_1, MIDI_PORT_1, PEDAL, "PRINZIPAL BASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop32(21, 15, MIDI_1, MIDI_PORT_1, PEDAL, "SUBBASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop33(22, 16, MIDI_1, MIDI_PORT_1, PEDAL, "OKTAVBASS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop34(23, 1, MIDI_1, MIDI_PORT_2, PEDAL, "BASSFLOTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop35(24, 2, MIDI_1, MIDI_PORT_2, PEDAL, "CHORALBASS", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop36(25, 3, MIDI_1, MIDI_PORT_2, PEDAL, "PEDAL MIXTUR 2F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop37(26, 4, MIDI_1, MIDI_PORT_2, PEDAL, "POSAUNE", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop38(27, 5, MIDI_1, MIDI_PORT_2, PEDAL, "TROMPETE", "8'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop39(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop40(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//#endif
//
//#ifdef FESTOSO_232T
//Stops stop0(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);//dodaj na konec odvisno kako je prva zamaknjena
//Stops stop1(0, 1, MIDI_2, MIDI_PORT_1, MANUAL_1, "BORDUN", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop2(1, 2, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop3(2, 3, MIDI_2, MIDI_PORT_1, MANUAL_1, "FLUTE HARMONIQ", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop4(3, 4, MIDI_2, MIDI_PORT_1, MANUAL_1, "SALICIONAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop5(4, 5, MIDI_2, MIDI_PORT_1, MANUAL_1, "OKTAVE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop6(5, 6, MIDI_2, MIDI_PORT_1, MANUAL_1, "SPITZFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop7(6, 7, MIDI_2, MIDI_PORT_1, MANUAL_1, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop8(7, 8, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL 2", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop9(8, 9, MIDI_2, MIDI_PORT_1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop10(9, 5, MIDI_2, MIDI_PORT_2, MANUAL_1, "TROMPETE 8", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop11(10, 11, MIDI_2, MIDI_PORT_1, MANUAL_1, "CLARION", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop12(I_PED, 0, 0, 0, 0, "I-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop13(SUB_I, 0, 0, 0, 0, "SUB I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop14(SUPER_I, 0, 0, 0, 0, "SUPER I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop15(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop16(11, 1, MIDI_1, MIDI_PORT_1, MANUAL_2, "PORTUNAL FLUTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop17(12, 2, MIDI_1, MIDI_PORT_1, MANUAL_2, "GAMBE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop18(13, 3, MIDI_1, MIDI_PORT_1, MANUAL_2, "VOX COELESTIS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop19(14, 4, MIDI_1, MIDI_PORT_1, MANUAL_2, "GEIGEN PRINZIPAL", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop20(15, 5, MIDI_1, MIDI_PORT_1, MANUAL_2, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop21(16, 6, MIDI_1, MIDI_PORT_1, MANUAL_2, "NASAT", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop22(17, 7, MIDI_1, MIDI_PORT_1, MANUAL_2, "FLAGEOLET", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop23(18, 8, MIDI_1, MIDI_PORT_1, MANUAL_2, "MIXTUR 4F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop24(19, 9, MIDI_1, MIDI_PORT_1, MANUAL_2, "LARIGOT", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop25(20, 6, MIDI_1, MIDI_PORT_2, MANUAL_2, "FAGOTT", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop26(21, 11, MIDI_1, MIDI_PORT_1, MANUAL_2, "OBOE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop27(22, 12, MIDI_1, MIDI_PORT_1, MANUAL_2, "TROMPETE HARMONIQE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop28(23, 13, MIDI_1, MIDI_PORT_1, MANUAL_2, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop29(NULL_address, TREMULANT_II, 0, 0, MANUAL_2, "TREMULANT", "manual II", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//
//Stops stop30(II_I, 0, 0, 0, 0, "II-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop31(II_PED, 0, 0, 0, 0, "II-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop32(SUB_II, 0, 0, 0, 0, "SUB II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop33(SUPER_II, 0, 0, 0, 0, "SUPER II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop34(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop35(24, 14, MIDI_1, MIDI_PORT_1, PEDAL, "PRINZIPAL BASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop36(25, 15, MIDI_1, MIDI_PORT_1, PEDAL, "SUBBASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop37(26, 16, MIDI_1, MIDI_PORT_1, PEDAL, "OKTAVBASS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop38(27, 1, MIDI_1, MIDI_PORT_2, PEDAL, "BASSFLOTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop39(28, 2, MIDI_1, MIDI_PORT_2, PEDAL, "CHORALBASS", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop40(29, 3, MIDI_1, MIDI_PORT_2, PEDAL, "PEDAL MIXTUR 2F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop41(30, 4, MIDI_1, MIDI_PORT_2, PEDAL, "POSAUNE", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop42(31, 5, MIDI_1, MIDI_PORT_2, PEDAL, "TROMPETE", "8'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop43(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop44(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop45(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop46(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop47(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//#endif
//
//
//
//
//#ifdef _RODGERS
//Stops stop0(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);//dodaj na konec odvisno kako je prva zamaknjena
//Stops stop1(0, 1, MIDI_2, MIDI_PORT_1, MANUAL_1, "BORDUN", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop2(1, 2, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop3(2, 3, MIDI_2, MIDI_PORT_1, MANUAL_1, "FLUTE HARMONIQ", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop4(3, 4, MIDI_2, MIDI_PORT_1, MANUAL_1, "SALICIONAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop5(4, 5, MIDI_2, MIDI_PORT_1, MANUAL_1, "OKTAVE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop6(5, 6, MIDI_2, MIDI_PORT_1, MANUAL_1, "SPITZFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop7(6, 7, MIDI_2, MIDI_PORT_1, MANUAL_1, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop8(7, 8, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL 2", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop9(8, 9, MIDI_2, MIDI_PORT_1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop10(9, 5, MIDI_2, MIDI_PORT_2, MANUAL_1, "TROMPETE 8", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop11(10, 11, MIDI_2, MIDI_PORT_1, MANUAL_1, "CLARION", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop12(NULL_address, I_PED, 0, 0, 0, "I-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop13(NULL_address, SUB_I, 0, 0, 0, "SUB I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop14(NULL_address, SUPER_I, 0, 0, 0, "SUPER I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop15(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop16(11, 1, MIDI_1, MIDI_PORT_1, MANUAL_2, "PORTUNAL FLUTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop17(12, 2, MIDI_1, MIDI_PORT_1, MANUAL_2, "GAMBE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop18(13, 3, MIDI_1, MIDI_PORT_1, MANUAL_2, "VOX COELESTIS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop19(14, 4, MIDI_1, MIDI_PORT_1, MANUAL_2, "GEIGEN PRINZIPAL", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop20(15, 5, MIDI_1, MIDI_PORT_1, MANUAL_2, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop21(16, 6, MIDI_1, MIDI_PORT_1, MANUAL_2, "NASAT", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop22(17, 7, MIDI_1, MIDI_PORT_1, MANUAL_2, "FLAGEOLET", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop23(18, 8, MIDI_1, MIDI_PORT_1, MANUAL_2, "MIXTUR 4F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop24(19, 9, MIDI_1, MIDI_PORT_1, MANUAL_2, "LARIGOT", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop25(20, 6, MIDI_1, MIDI_PORT_2, MANUAL_2, "FAGOTT", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop26(21, 11, MIDI_1, MIDI_PORT_1, MANUAL_2, "OBOE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop27(22, 12, MIDI_1, MIDI_PORT_1, MANUAL_2, "TROMPETE HARMONIQE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop28(23, 13, MIDI_1, MIDI_PORT_1, MANUAL_2, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop29(NULL_address, TREMULANT_I, 0, 0, 0, "TREMULANT", "manual I", &on_Stop_tremulant_man_II, &on_Stop_tremulant_man_II);
//
//Stops stop30(NULL_address, II_I, 0, 0, 0, "II-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop31(NULL_address, II_PED, 0, 0, 0, "II-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop32(NULL_address, SUB_II, 0, 0, 0, "SUB II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop33(NULL_address, SUPER_II, 0, 0, 0, "SUPER II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop34(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop35(24, 14, MIDI_1, MIDI_PORT_1, PEDAL, "PRINZIPAL BASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop36(25, 15, MIDI_1, MIDI_PORT_1, PEDAL, "SUBBASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop37(26, 16, MIDI_1, MIDI_PORT_1, PEDAL, "OKTAVBASS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop38(27, 1, MIDI_1, MIDI_PORT_2, PEDAL, "BASSFLOTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop39(28, 2, MIDI_1, MIDI_PORT_2, PEDAL, "CHORALBASS", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop40(29, 3, MIDI_1, MIDI_PORT_2, PEDAL, "PEDAL MIXTUR 2F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop41(30, 4, MIDI_1, MIDI_PORT_2, PEDAL, "POSAUNE", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop42(31, 5, MIDI_1, MIDI_PORT_2, PEDAL, "TROMPETE", "8'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop43(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop44(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop45(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop46(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop47(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//#endif
//////VELIK IGRALNIK manubriji
////
//#ifdef _DRAW_KNOB
//
//Stops stop0(0, 5, MIDI_1, MIDI_PORT_2, PEDAL, "TROMPETE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop1(1, 4, MIDI_1, MIDI_PORT_2, PEDAL, "POSAUNE", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop2(2, 15, MIDI_1, MIDI_PORT_1, PEDAL, "SUBBASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop3(3, 14, MIDI_1, MIDI_PORT_1, PEDAL, "PRINZIPAL BASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop4(4, 16, MIDI_1, MIDI_PORT_1, PEDAL, "OKTAVBASS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop5(5, 1, MIDI_1, MIDI_PORT_2, PEDAL, "BASSFLOTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop6(6, 2, MIDI_1, MIDI_PORT_2, PEDAL, "CHORALBASS", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop7(7, 3, MIDI_1, MIDI_PORT_2, PEDAL, "PEDAL MIXTUR 2F.", "2'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop8(8, 11, MIDI_2, MIDI_PORT_1, MANUAL_1, "CLARION", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop9(9, 7, MIDI_2, MIDI_PORT_1, MANUAL_1, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);//2 quinta sta preveri
//Stops stop10(10, 8, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL 2", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop11(11, 9, MIDI_2, MIDI_PORT_1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop12(12, 5, MIDI_2, MIDI_PORT_2, MANUAL_1, "TROMPETE 8", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop13(13, 1, MIDI_2, MIDI_PORT_1, MANUAL_1, "BORDUN", "16'", &on_stop_ON, &on_stop_OFF);//PREVERI
//Stops stop14(14, 2, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop15(15, 3, MIDI_2, MIDI_PORT_1, MANUAL_1, "FLUTE HARMONIQ", "8'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop16(NULL_address, 0, 0, 0, MANUAL_2, "null", "", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);//NI GA
//Stops stop17(16, 4, MIDI_2, MIDI_PORT_1, MANUAL_1, "SALICIONAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop18(17, 5, MIDI_2, MIDI_PORT_1, MANUAL_1, "OKTAVE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop19(18, 6, MIDI_2, MIDI_PORT_1, MANUAL_1, "SPITZFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop20(NULL_address, SUPER_I, 0, 0, 0, "SUPER I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop21(NULL_address, SUB_I, 0, 0, 0, "SUB I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop22(NULL_address, II_I, 0, 0, 0, "II-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop23(NULL_address, III_PED, 0, 0, 0, "III-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop24(NULL_address, I_PED, 0, 0, 0, "I-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop25(NULL_address, II_PED, 0, 0, 0, "II-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//
//
//
//Stops stop26(NULL_address, SUPER_III, 0, 0, 0, "SUPER III", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop27(NULL_address, SUPER_II, 0, 0, 0, "SUPER II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop28(NULL_address, SUB_III, 0, 0, 0, "SUB III", "", &on_stop_ON, &on_Stop_oktav_OFF);//poglej to
//
//Stops stop29(NULL_address, SUB_II, 0, 0, 0, "SUB II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//
//Stops stop30(NULL_address, III_II, 0, 0, 0, "III-II", "", &on_stop_ON, &on_stop_OFF);
//Stops stop31(NULL_address, III_I, 0, 0, 0, "III-I", "", &on_stop_ON, &on_stop_OFF);
//
//
//
//Stops stop40(19, 1, MIDI_1, MIDI_PORT_1, MANUAL_3, "PORTUNAL FLUTE", "8'", &on_stop_ON, &on_stop_OFF);// (39, TREMULANT_II, 0, 0, 0, "TREMULANT", "manual II", &on_Stop_tremulant, &on_stop_OFF_tremulant);//TODO: veži funkcijo, ki posebaj pošlje ukaz
//
//Stops stop41(20, 2, MIDI_1, MIDI_PORT_1, MANUAL_3, "GAMBE", "8'", &on_stop_ON, &on_stop_OFF); //(40, 4, MIDI_2, MIDI_PORT_2, MANUAL_2, "KRUMMHORN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop42(21, 3, MIDI_1, MIDI_PORT_1, MANUAL_3, "VOX COELESTIS", "8'", &on_stop_ON, &on_stop_OFF);// (41, 16, MIDI_2, MIDI_PORT_1, MANUAL_2, "GEMSHORN", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop43(22, 5, MIDI_1, MIDI_PORT_1, MANUAL_3, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);// (42, 1, MIDI_2, MIDI_PORT_2, MANUAL_2, "TERZE", "1 3/5''", &on_stop_ON, &on_stop_OFF);
//Stops stop44(23, 4, MIDI_1, MIDI_PORT_1, MANUAL_3, "GEIGEN PRINZIPAL", "4'", &on_stop_ON, &on_stop_OFF);// (43, 3, MIDI_2, MIDI_PORT_2, MANUAL_2, "SCHARF 3F.", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop45(24, 6, MIDI_1, MIDI_PORT_1, MANUAL_3, "NASAT", "2 2/3'", &on_stop_ON, &on_stop_OFF); //(44, 2, MIDI_2, MIDI_PORT_2, MANUAL_2, "PICCOLO", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop46(25, 12, MIDI_1, MIDI_PORT_1, MANUAL_3, "TROMPETE HARMONIQE", "8'", &on_stop_ON, &on_stop_OFF);// (45, 12, MIDI_2, MIDI_PORT_1, MANUAL_2, "BORDON", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop47(26, 11, MIDI_1, MIDI_PORT_1, MANUAL_3, "OBOE", "8'", &on_stop_ON, &on_stop_OFF);// (46, 13, MIDI_2, MIDI_PORT_1, MANUAL_2, "PRESTANT", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop48(27, 2, MIDI_2, MIDI_PORT_2, MANUAL_2, "PICCOLO", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop49(28, 3, MIDI_2, MIDI_PORT_2, MANUAL_2, "SCHARF 3F.", "1'", &on_stop_ON, &on_stop_OFF);// (48, 15, MIDI_2, MIDI_PORT_1, MANUAL_2, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop50(29, 1, MIDI_2, MIDI_PORT_2, MANUAL_2, "TERZE", "1 3/5''", &on_stop_ON, &on_stop_OFF);// (49, TREMULANT_I, 0, 0, 0, "TREMULANT", "manual I", &on_stop_ON, &on_stop_OFF);
//
//Stops stop35(30, 16, MIDI_2, MIDI_PORT_1, MANUAL_2, "GEMSHORN", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop36(31, 4, MIDI_2, MIDI_PORT_2, MANUAL_2, "KRUMMHORN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop37(NULL_address, TREMULANT_I, 0, 0, 0, "TREMULANT", "manual I", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//Stops stop38(32, 13, MIDI_1, MIDI_PORT_1, MANUAL_3, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop39(NULL_address, TREMULANT_II, 0, 0, MANUAL_3, "TREMULANT", "manual II", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//Stops stop51(33, 15, MIDI_2, MIDI_PORT_1, MANUAL_2, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF); //(50, 13, MIDI_1, MIDI_PORT_1, MANUAL_3, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop52(34, 14, MIDI_2, MIDI_PORT_1, MANUAL_2, "ROHRFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop53(35, 13, MIDI_2, MIDI_PORT_1, MANUAL_2, "PRESTANT", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop54(36, 12, MIDI_2, MIDI_PORT_1, MANUAL_2, "BORDUN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop55(37, 7, MIDI_1, MIDI_PORT_1, MANUAL_2, "FLAGEOLET", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop32(38, 8, MIDI_1, MIDI_PORT_1, MANUAL_3, "MIXTUR 4F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop33(39, 9, MIDI_1, MIDI_PORT_1, MANUAL_3, "LARIGOT", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop34(40, 6, MIDI_1, MIDI_PORT_2, MANUAL_3, "FAGOTT", "16'", &on_stop_ON, &on_stop_OFF);// (33, 5, MIDI_1, MIDI_PORT_1, MANUAL_3, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);
//#endif // _DRAW_KNOB
//
//
//
//#ifdef _AMERIKA_DEMO
//
//Stops stop0(TROMPETE_8_ped, 5, MIDI_1, MIDI_PORT_2, PEDAL, "TROMPETE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop1(POSAUNE_16, 4, MIDI_1, MIDI_PORT_2, PEDAL, "POSAUNE", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop2(PEDAL_MIXTUR_2F, 3, MIDI_1, MIDI_PORT_2, PEDAL, "PEDAL MIXTUR 2F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop3(CHORALBASS_4, 2, MIDI_1, MIDI_PORT_2, PEDAL, "CHORALBASS", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop4(BASSFLOTE_8, 1, MIDI_1, MIDI_PORT_2, PEDAL, "BASSFLOTE", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop5(OKTAVBASS_8, 16, MIDI_1, MIDI_PORT_1, PEDAL, "OKTAVBASS", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop6(SUBBASS_8, 15, MIDI_1, MIDI_PORT_1, PEDAL, "SUBBASS", "16'", &on_stop_ON, &on_stop_OFF);
//Stops stop7(PRINZIPAL_BASS_16, 14, MIDI_1, MIDI_PORT_1, PEDAL, "PRINZIPAL BASS", "16'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop8(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop9(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop10(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop11(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop12(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop13(CLARION_4, 11, MIDI_2, MIDI_PORT_1, MANUAL_1, "CLARION", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop14(TROMPETE_8, 5, MIDI_2, MIDI_PORT_2, MANUAL_1, "TROMPETE 8", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop15(MIXTUR_5F, 9, MIDI_2, MIDI_PORT_1, MANUAL_1, "MIXTUR 5F.", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop16(PRINZIPAL_2, 8, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL 2", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop17(QUINTE, 7, MIDI_2, MIDI_PORT_1, MANUAL_1, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);//2 quinta sta preveri
//Stops stop18(SPITZFLOTE, 6, MIDI_2, MIDI_PORT_1, MANUAL_1, "SPITZFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop19(OKTAVE_4, 5, MIDI_2, MIDI_PORT_1, MANUAL_1, "OKTAVE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop20(SALICIONAL, 4, MIDI_2, MIDI_PORT_1, MANUAL_1, "SALICIONAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop21(FLUTE_HARMONIQ, 3, MIDI_2, MIDI_PORT_1, MANUAL_1, "FLUTE HARMONIQ", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop22(PRINZIPAL_8, 2, MIDI_2, MIDI_PORT_1, MANUAL_1, "PRINZIPAL", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop23(BORDUN_16, 1, MIDI_2, MIDI_PORT_1, MANUAL_1, "BORDUN", "16'", &on_stop_ON, &on_stop_OFF);//PREVERI
//
//Stops stop24(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop25(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//Stops stop27(NULL_address, I_PED, 0, 0, 0, "I-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop37(NULL_address, II_PED, 0, 0, 0, "II-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop26(NULL_address, III_PED, 0, 0, 0, "III-PEDAL", "", &on_stop_ON, &on_stop_OFF);
//Stops stop29(NULL_address, II_I, 0, 0, 0, "II-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop30(NULL_address, SUPER_I, 0, 0, MANUAL_1, "SUPER I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop31(NULL_address, SUB_I, 0, 0, MANUAL_1, "SUB I", "", &on_stop_ON, &on_Stop_oktav_OFF);
//
//
//
//Stops stop28(NULL_address, III_I, 0, 0, 0, "III-I", "", &on_stop_ON, &on_stop_OFF);
//Stops stop36(NULL_address, III_II, 0, 0, 0, "III-II", "", &on_stop_ON, &on_stop_OFF);
//Stops stop34(NULL_address, SUB_II, 0, 0, MANUAL_2, "SUB II", "", &on_stop_ON, &on_Stop_oktav_OFF);//poglej to
//Stops stop32(NULL_address, SUB_III, 0, 0, MANUAL_3, "SUB III", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop35(NULL_address, SUPER_II, 0, 0, MANUAL_2, "SUPER II", "", &on_stop_ON, &on_Stop_oktav_OFF);
//Stops stop33(NULL_address, SUPER_III, 0, 0, MANUAL_3, "SUPER III", "", &on_stop_ON, &on_Stop_oktav_OFF);
//
//Stops stop38(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//Stops stop39(NULL_address, -1, -1, -1, -1, "", "", &on_Stop_dummy, &on_Stop_dummy);
//
//
//Stops stop56(BORDUN_8, 12, MIDI_2, MIDI_PORT_1, MANUAL_2, "BORDUN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop57(PRESTANT_4, 13, MIDI_2, MIDI_PORT_1, MANUAL_2, "PRESTANT", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop58(ROHRFLOTE_4, 14, MIDI_2, MIDI_PORT_1, MANUAL_2, "ROHRFLOTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop59(QUINTE_m3, 15, MIDI_2, MIDI_PORT_1, MANUAL_2, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF); //(50, 13, MIDI_1, MIDI_PORT_1, MANUAL_3, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop60(GEMSHORN_2, 16, MIDI_2, MIDI_PORT_1, MANUAL_2, "GEMSHORN", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop61(TERZE_m3, 1, MIDI_2, MIDI_PORT_2, MANUAL_2, "TERZE", "1 3/5''", &on_stop_ON, &on_stop_OFF);// (49, TREMULANT_I, 0, 0, 0, "TREMULANT", "manual I", &on_stop_ON, &on_stop_OFF);
//Stops stop62(PICCOLO, 2, MIDI_2, MIDI_PORT_2, MANUAL_2, "PICCOLO", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop63(SCHARF_3F, 3, MIDI_2, MIDI_PORT_2, MANUAL_2, "SCHARF 3F.", "1'", &on_stop_ON, &on_stop_OFF);// (48, 15, MIDI_2, MIDI_PORT_1, MANUAL_2, "QUINTE", "2 2/3'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop48(KRUMHORN, 4, MIDI_2, MIDI_PORT_2, MANUAL_2, "KRUMMHORN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop49(NULL_address, TREMULANT_I, 0, 0, MANUAL_2, "TREMULANT", "manual I", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//Stops stop40(PORTUNAL_FLOTE, 1, MIDI_1, MIDI_PORT_1, MANUAL_3, "PORTUNAL FLUTE", "8'", &on_stop_ON, &on_stop_OFF);// (39, TREMULANT_II, 0, 0, 0, "TREMULANT", "manual II", &on_Stop_tremulant, &on_stop_OFF_tremulant);//TODO: veži funkcijo, ki posebaj pošlje ukaz
//Stops stop41(GAMBE, 2, MIDI_1, MIDI_PORT_1, MANUAL_3, "GAMBE", "8'", &on_stop_ON, &on_stop_OFF); //(40, 4, MIDI_2, MIDI_PORT_2, MANUAL_2, "KRUMMHORN", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop42(VOX_COELESTIS, 3, MIDI_1, MIDI_PORT_1, MANUAL_3, "VOX COELESTIS", "8'", &on_stop_ON, &on_stop_OFF);// (41, 16, MIDI_2, MIDI_PORT_1, MANUAL_2, "GEMSHORN", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop43(GEIGEN_PRINZIPAL, 4, MIDI_1, MIDI_PORT_1, MANUAL_3, "GEIGEN PRINZIPAL", "4'", &on_stop_ON, &on_stop_OFF);// (43, 3, MIDI_2, MIDI_PORT_2, MANUAL_2, "SCHARF 3F.", "1'", &on_stop_ON, &on_stop_OFF);
//Stops stop44(TRAVERS_FLUTE, 5, MIDI_1, MIDI_PORT_1, MANUAL_3, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);// (42, 1, MIDI_2, MIDI_PORT_2, MANUAL_2, "TERZE", "1 3/5''", &on_stop_ON, &on_stop_OFF);
//Stops stop45(NASAT, 6, MIDI_1, MIDI_PORT_1, MANUAL_3, "NASAT", "2 2/3'", &on_stop_ON, &on_stop_OFF); //(44, 2, MIDI_2, MIDI_PORT_2, MANUAL_2, "PICCOLO", "1'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop46(FLAGEOLET, 7, MIDI_1, MIDI_PORT_1, MANUAL_3, "FLAGEOLET", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop47(MIXTUR_4F, 8, MIDI_1, MIDI_PORT_1, MANUAL_3, "MIXTUR 4F.", "2'", &on_stop_ON, &on_stop_OFF);
//Stops stop51(LARIGOT, 9, MIDI_1, MIDI_PORT_1, MANUAL_3, "LARIGOT", "1 1/3'", &on_stop_ON, &on_stop_OFF);
//Stops stop52(FAGOTT, 6, MIDI_1, MIDI_PORT_2, MANUAL_3, "FAGOTT", "16'", &on_stop_ON, &on_stop_OFF);// (33, 5, MIDI_1, MIDI_PORT_1, MANUAL_3, "TRAVERS FLUTE", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop53(OBOE, 11, MIDI_1, MIDI_PORT_1, MANUAL_3, "OBOE", "8'", &on_stop_ON, &on_stop_OFF);// (46, 13, MIDI_2, MIDI_PORT_1, MANUAL_2, "PRESTANT", "4'", &on_stop_ON, &on_stop_OFF);
//Stops stop54(TROMPETE_HARMONIQ, 12, MIDI_1, MIDI_PORT_1, MANUAL_3, "TROMPETE HARMONIQE", "8'", &on_stop_ON, &on_stop_OFF);// (45, 12, MIDI_2, MIDI_PORT_1, MANUAL_2, "BORDON", "8'", &on_stop_ON, &on_stop_OFF);
//Stops stop55(SCHALMEI, 13, MIDI_1, MIDI_PORT_1, MANUAL_3, "SCHALMEI", "4'", &on_stop_ON, &on_stop_OFF);
//
//Stops stop50(NULL_address, TREMULANT_II, 0, 0, MANUAL_3, "TREMULANT", "manual II", &on_stop_tremulant_ON, &on_stop_tremulant_OFF);
//
//
//
//
//#endif // _DRAW_KNOB
//#endif // pokazi