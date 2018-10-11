!  Copyright (C) 2017 Jussi Pakkanen.
!
! This program is free software; you can redistribute it and/or modify it under
! the terms of version 3, or (at your option) any later version,
! of the GNU General Public License as published
! by the Free Software Foundation.
! 
! This program is distributed in the hope that it will be useful, but WITHOUT
! ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
! FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
! details.
!
! You should have received a copy of the GNU General Public License
! along with this program.  If not, see <http://www.gnu.org/licenses/>.

function fortranfunc() result(msg_ptr) bind(c, name='fortranfunc')
  use, intrinsic :: iso_c_binding, only: &
       c_ptr, c_char, C_CHAR, C_NEW_LINE, C_NULL_CHAR, c_loc
  type(c_ptr) :: msg_ptr
  ! NOTE: `save` is necessary here to make sure that the pointer
  !       continues to point to valid memory.
  character(kind=c_char, len=34), target, save :: msg

  msg = C_CHAR_"This line is created in Fortran."//C_NEW_LINE//C_NULL_CHAR
  msg_ptr = c_loc(msg)

end function fortranfunc
