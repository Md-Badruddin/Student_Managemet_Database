import React, { useEffect, useState } from 'react';
import Layout from '../../components/Layout';
import DataTable from '../../components/DataTable';
import { fetchPatients } from '../../lib/api';

const PatientsPage = () => {
    const [patients, setPatients] = useState([]);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        const getPatients = async () => {
            const data = await fetchPatients();
            setPatients(data);
            setLoading(false);
        };

        getPatients();
    }, []);

    if (loading) {
        return <div>Loading...</div>;
    }

    return (
        <Layout>
            <h1>Patients List</h1>
            <DataTable data={patients} />
        </Layout>
    );
};

export default PatientsPage;