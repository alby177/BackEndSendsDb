#ifndef MEXTYPES_H
#define MEXTYPES_H

// Enumerator for available database management functions
enum mexTypes
{
    openDb,
    createTable,
    deleteTable,
    insertValues,
    showValues,
    closeDb,
    ackCmd,
    values,
    error,
};

#endif // MEXTYPES_H
