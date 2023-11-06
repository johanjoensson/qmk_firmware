void leader_start_user(void) {
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_U)) {
        // tap_code16(UC(9829));
        SEND_STRING("Enter unicode mnemonic (snek)");
        ucis_start();
    }
}

