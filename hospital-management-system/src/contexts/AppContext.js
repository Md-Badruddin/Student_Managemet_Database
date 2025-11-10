import React, { createContext, useState, useContext } from 'react';

const AppContext = createContext();

export const AppProvider = ({ children }) => {
    const [patients, setPatients] = useState([]);
    const [appointments, setAppointments] = useState([]);

    return (
        <AppContext.Provider value={{ patients, setPatients, appointments, setAppointments }}>
            {children}
        </AppContext.Provider>
    );
};

export const useAppContext = () => {
    return useContext(AppContext);
};