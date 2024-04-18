function! BerSyntax()
if expand('%:e') == 'ber'

highlight berDefault ctermfg=white ctermbg=red
syntax match berDefault /./

highlight ber0 ctermfg=grey
syntax match ber0 /0/

highlight ber1 cterm=bold ctermfg=white
syntax match ber1 /1/

highlight berP cterm=bold ctermfg=blue
syntax match berP /P/

highlight berC cterm=bold ctermfg=yellow
syntax match berC /C/

highlight berE cterm=bold ctermfg=green
syntax match berE /E/

highlight berF cterm=bold ctermfg=red
syntax match berF /F/

highlight berB cterm=bold ctermfg=grey
syntax match berB /B/

endif
endfunction
autocmd BufReadPost * call BerSyntax()
