import React, { useEffect, useState } from 'react';
import Link from 'next/link';
import DataTable from '../../components/DataTable';
import Layout from '../../components/Layout';
import { fetchAppointments } from '../../lib/api';

const AppointmentsPage = () => {
    const [appointments, setAppointments] = useState([]);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        const getAppointments = async () => {
            const data = await fetchAppointments();
            setAppointments(data);
            setLoading(false);
        };

        getAppointments();
    }, []);

    if (loading) {
        return <div>Loading...</div>;
    }

    return (
        <Layout>
            <h1>Appointments</h1>
            <Link href="/appointments/new">Create New Appointment</Link>
            <DataTable data={appointments} />
        </Layout>
    );
};

export default AppointmentsPage;