def cutting(wire, minimum_cuts):
    if(wire > 1):
        minimum_cuts += 1
        return cutting(wire/2, minimum_cuts)
    else:
        return minimum_cuts


wire = 12
print(wire," meter steel wire is needed" ,cutting(wire, 0)," minimum number of cuts")
