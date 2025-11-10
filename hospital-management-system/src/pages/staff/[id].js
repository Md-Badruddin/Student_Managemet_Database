import { useEffect, useState } from 'react';
import { useRouter } from 'next/router';
import Layout from '../../components/Layout';

const StaffDetail = () => {
    const router = useRouter();
    const { id } = router.query;
    const [staffMember, setStaffMember] = useState(null);
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        if (id) {
            // Fetch staff member details from API
            const fetchStaffMember = async () => {
                const response = await fetch(`/api/staff/${id}`);
                const data = await response.json();
                setStaffMember(data);
                setLoading(false);
            };

            fetchStaffMember();
        }
    }, [id]);

    if (loading) {
        return <div>Loading...</div>;
    }

    if (!staffMember) {
        return <div>Staff member not found.</div>;
    }

    return (
        <Layout>
            <h1>{staffMember.name}</h1>
            <p>Position: {staffMember.position}</p>
            <p>Email: {staffMember.email}</p>
            <p>Phone: {staffMember.phone}</p>
            <p>Department: {staffMember.department}</p>
        </Layout>
    );
};

export default StaffDetail;