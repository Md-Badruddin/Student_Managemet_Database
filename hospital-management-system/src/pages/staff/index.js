import React, { useEffect, useState } from 'react';
import Link from 'next/link';
import Layout from '../../components/Layout';
import DataTable from '../../components/DataTable';
import { fetchStaff } from '../../lib/api';

const StaffPage = () => {
    const [staffMembers, setStaffMembers] = useState([]);

    useEffect(() => {
        const getStaffMembers = async () => {
            const data = await fetchStaff();
            setStaffMembers(data);
        };
        getStaffMembers();
    }, []);

    return (
        <Layout>
            <h1>Staff Members</h1>
            <Link href="/staff/new">Add New Staff</Link>
            <DataTable data={staffMembers} />
        </Layout>
    );
};

export default StaffPage;