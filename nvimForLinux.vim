"language en_US.utf8
"set langmenu=en_US.UTF-8
"language en
"let mapleader = ","

"clone file to git
"nnoremap <c-c> :w<cr>:!mklink /h C:/Users/user/Documents/paul_file/git/a %<cr>:!ren C:/Users/user/Documents/paul_file/git/a %<cr><cr>

"tab
nnoremap <tab> >>
nnoremap <bs> <<
vnoremap <tab> >
vnoremap <bs> <

"'({[
"inoremap ( ()<left>
"inoremap { { <bs>}<left>
"au filetype c inoremap ' ''<left>
"au filetype cpp inoremap ' ''<left>
"au filetype python inoremap ' ''<left>
"au filetype java inoremap ' ''<left>
"au filetype c inoremap " ""<left>
"au filetype cpp inoremap " ""<left>
"au filetype python inoremap " ""<left>
"au filetype java inoremap " ""<left>
"au filetype python inoremap [ []<left>

";
au filetype c inoremap <c-;> <esc>A;
au filetype c nnoremap <c-;> A;<esc>
au filetype cpp inoremap <c-;> <esc>A;
au filetype cpp nnoremap <c-;> A;<esc>
au filetype java inoremap <c-;> <esc>A;
au filetype java nnoremap <c-;> A;<esc>
au filetype python inoremap <c-;> <esc>A:<ENTER>

"file refresh
inoremap <F5> <esc>:source ~/.config/nvim/init.vim<cr>
nnoremap <F5> :source ~/.config/nvim/init.vim<cr>
inoremap <c-6> <esc>:w<cr><c-6>
nnoremap <c-6> :w<cr><c-6>

"normal cr
au filetype cpp nnoremap <A-[> A{<ENTER>}<esc>O
au filetype c nnoremap <A-[> A{<ENTER>}<esc>O
au filetype java nnoremap <A-[> A{<ENTER>}<esc>O
au filetype cpp inoremap <A-[> <esc>A{<ENTER>}<esc>O
au filetype c inoremap <A-[> <esc>A{<ENTER>}<esc>O
au filetype java inoremap <A-[> <esc>A{<ENTER>}<esc>O
nnoremap <ENTER> o<esc>
nnoremap <S-ENTER> O<esc>

"compile
au filetype c nnoremap <F2> :w<cr>:!gcc -std=c99 "%"<cr>
au filetype c inoremap <F2> <esc>:w<cr>:!gcc -std=c99 "%"<cr>
au filetype cpp nnoremap <F2> :w<cr>:!g++ "%"<cr>
au filetype cpp nnoremap <F2> <esc>:w<cr>:!g++ "%"<cr>

"compile & run
au filetype c nnoremap <F3> :w<cr>:!gcc -std=c99 "%" & ./a.out<cr>
au filetype c inoremap <F3> <esc>:w<cr>:!gcc -std=c99 "%" & ./a.out<cr>
au filetype cpp nnoremap <F3> :w<cr>:!g++ "%" & ./a.out<cr>
au filetype cpp nnoremap <F3> <esc>:w<cr>:!g++ "%" & ./a.out<cr>
au filetype python nnoremap <F3> :w<cr>:!python "%"<cr>
au filetype python inoremap <F3> <esc>:w<cr>:!python "%"<cr>
au filetype java nnoremap <F3> :w<cr>:!java "%"<cr>
au filetype java inoremap <F3> <esc>:w<cr>:!java "%"<cr>

"debugger
au filetype c nnoremap <F4> :w<cr>:!gcc -std=c99 -g "%"<cr>
au filetype cpp nnoremap <F4> :w<cr>:!g++ -g "%"<cr>
au filetype python nnoremap <F4> :w<cr>:!copy "%" debug.py<cr>

"comments
au filetype cpp noremap <c-/> mzI//<esc>`z
au filetype cpp inoremap <c-/> <esc>mzI//<esc>`zla
au filetype cpp inoremap /* /**/<left><left>
au filetype c noremap <c-/> mzI//<esc>`z
au filetype c inoremap <c-/> <esc>mzI//<esc>`zla
au filetype c inoremap /* /**/<left><left>
au filetype python  noremap <c-/> mzI#<esc>`z
au filetype python  inoremap <c-/> <esc>mzI#<esc>`zla

syntax on
filetype on
filetype indent on
filetype plugin on
set fileformat=unix

"set t_Co = 256 "set 256 color but it will error
set nu rnu "relative line number
set nu "absolute line number
set ruler "cursor line number
set incsearch "reinforce search

"set ignorecase "ignore upper lower
set cursorline
set cursorcolumn

" Color configuration
"set bg=dark
color evening  " Same as :colorscheme evening
hi CursorLineNr ctermfg=Green ctermbg=black cterm=bold
hi CursorColumn ctermfg=Green ctermbg=black cterm=None
hi CursorLine ctermfg=green ctermbg=black cterm=bold
set wrap
set ai "auto intent
set smartindent
set tabstop=4
set shiftwidth=4
set backspace=2
set noswapfile
set showtabline=2
set splitbelow "new at below
set splitright "vnew at right
set hlsearch
