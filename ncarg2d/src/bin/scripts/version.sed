#!/bin/csh -f
#
#	$Id: version.sed,v 1.13 2000-03-22 00:31:46 haley Exp $
#

set year = "2000"
set sitefile = `ncargpath NCARGDIR`/NCARGSITEFILE
if (-f $sitefile) then
  set sitenum = `head -1 $sitefile`
else
  set sitenum = "Site ID Number undefined for support."
endif  

if ($#argv > 0) then
  if ("$1" == "-v") echo VERSION
else

echo ""
cat <<EOF
------------------------------------------------------------------------------
NCAR Graphics Software and Documentation
------------------------------------------------------------------------------
  Version        : VERSION

  Site ID Number : $sitenum

  Copyright (C)  : 1987-$year, University Corporation for Atmospheric Research

  Trademark      : NCAR Graphics is a registered trademark of the University
                   Corporation for Atmospheric Research.

  License        : The use of NCAR Graphics software and documentation is
                   governed by a License Agreement.
------------------------------------------------------------------------------
EOF
echo ""
endif
