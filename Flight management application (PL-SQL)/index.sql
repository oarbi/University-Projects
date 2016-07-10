CREATE INDEX rech_vol
ON Vol(villedep,villearr);

CREATE INDEX rech_av
ON Avion(codetype);
  
CREATE INDEX rech_aff
ON Affectation(nupilote,nuavion);

CREATE INDEX rech_ap
ON Appareil(nbrplaces);