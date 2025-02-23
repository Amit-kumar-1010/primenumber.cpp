#include <iostream>
using namespace std;
int main()
{
  int n,m=0,i,flag=0;
  cout<<"entre the number to check prime ";
  cin>>n;
  m=n/2;
  for(int i=2;i<=m;i++)
    {
      if(n%i==0)
      {
        cout<<"number is not prime"<<endl;
        flag=1;
        break;
      }
    }
  if(flag==0)
  
    cout<<"number is prime"<<endl;
    return 0;
  }
// }






import React, { useState, useEffect } from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import { InfoCircle } from 'react-bootstrap-icons';
import { parse, differenceInDays } from 'date-fns';

import header1 from '../Image/header1.jpg';
import Dis from '../Image/Icon Button - Medium.svg';
import Dis1 from '../Image/warning.svg';
import Dis2 from '../Image/open_in_new.svg';
import Dis3 from '../Image/AdobeStock_340642333 1.svg';

const GratuityCalculator = () => {
    const [arrivalDate, setArrivalDate] = useState('');
    const [departureDate, setDepartureDate] = useState('');
    const [daysSpent, setDaysSpent] = useState('');
    const [showServicePeriodForm, setShowServicePeriodForm] = useState(false);
    const [joiningDate, setJoiningDate] = useState('');
    const [retirementDate, setRetirementDate] = useState('');
    const [servicePeriod, setServicePeriod] = useState('');
    const [averageSalary, setAverageSalary] = useState('');
    const [isGratuityActChecked, setIsGratuityActChecked] = useState(false);

    const [showAverageSalaryForm, setShowAverageSalaryForm] = useState(false);

    const [isPieceRateChecked, setIsPieceRateChecked] = useState(false);
    const [isSeasonalEstablishmentChecked, setIsSeasonalEstablishmentChecked] = useState(false);



    const [tenMonthsData, setTenMonthsData] = useState(
        Array.from({ length: 10 }, (_, i) => ({
            month: i + 1,
            arrivalDate: '',
            departureDate: '',
            daysSpent: ''
        }))
    );

    const [totalSalaryFor10Months, setTotalSalaryFor10Months] = useState('');
    const [averageSalaryFor10Months, setAverageSalaryFor10Months] = useState('');

    useEffect(() => {
        if (arrivalDate && departureDate) {
            try {
                const parsedArrivalDate = parse(arrivalDate, 'dd/MM/yyyy', new Date());
                const parsedDepartureDate = parse(departureDate, 'dd/MM/yyyy', new Date());
                const diff = differenceInDays(parsedDepartureDate, parsedArrivalDate);
                setDaysSpent(diff >= 0 ? diff : '');
            } catch (error) {
                console.error("Error parsing dates:", error);
                setDaysSpent('');
            }
        } else {
            setDaysSpent('');
        }
    }, [arrivalDate, departureDate]);

    const handleCalculateServicePeriod = () => {
        setShowServicePeriodForm(true);
    };
    const handleDisclaimerClick = () => {

        console.log('Disclaimer clicked');
    };
    const handleHeaderLinkClick = (linkType) => {

        console.log(`${linkType} clicked`);
    };

    const handleGratuityActChange = () => {
        setIsGratuityActChecked(!isGratuityActChecked);

        // If unchecking the first checkbox, uncheck the other two
        if (!isGratuityActChecked) {
            setIsPieceRateChecked(false);
            setIsSeasonalEstablishmentChecked(false);
        }
    };

    const handlePieceRateChange = () => {
        setIsPieceRateChecked(!isPieceRateChecked);
    };

    const handleSeasonalEstablishmentChange = () => {
        setIsSeasonalEstablishmentChecked(!isSeasonalEstablishmentChecked);
    };
    const handleSubmitServicePeriod = () => {
        if (joiningDate && retirementDate) {
            try {
                const parsedJoiningDate = parse(joiningDate, 'dd/MM/yyyy', new Date());
                const parsedRetirementDate = parse(retirementDate, 'dd/MM/yyyy', new Date());
                const diffInDays = differenceInDays(parsedRetirementDate, parsedJoiningDate);

                const years = Math.floor(diffInDays / 365);
                const remainingDays = diffInDays % 365;
                const months = Math.floor(remainingDays / 30);
                const days = remainingDays % 30;

                setServicePeriod(`${years}Y ${months}M ${days}D`);
            } catch (error) {
                console.error("Error parsing dates:", error);
                setServicePeriod('Invalid Date');
            }
        }
        setShowServicePeriodForm(false);
    };

    const handleOpenAverageSalaryForm = () => {
        setShowAverageSalaryForm(true);
    };

    const handleRowChange = (index, field, value) => {
        const newData = [...tenMonthsData];
        newData[index][field] = value;


        const { arrivalDate, departureDate } = newData[index];
        if (arrivalDate && departureDate) {
            try {
                const parsedArrival = parse(arrivalDate, 'dd/MM/yyyy', new Date());
                const parsedDeparture = parse(departureDate, 'dd/MM/yyyy', new Date());
                const diff = differenceInDays(parsedDeparture, parsedArrival);
                newData[index].daysSpent = diff >= 0 ? diff : '';
            } catch (error) {
                newData[index].daysSpent = '';
            }
        } else {
            newData[index].daysSpent = '';
        }

        setTenMonthsData(newData);
    };


    const handleSubmitAverageSalary = () => {

        let avg = '';
        if (!isNaN(totalSalaryFor10Months) && totalSalaryFor10Months !== '') {
            avg = (Number(totalSalaryFor10Months) / 10).toFixed(2);
        }
        setAverageSalaryFor10Months(avg);

        setAverageSalary(avg);

        setShowAverageSalaryForm(false);
    };

    return (

        <div className="min-vh-100 bg-light py-4">
            <div className="container-fluid">
                {/* Add the new header image */}
                <div className="mb-0 relative">
                    <img
                        src={Dis3}
                        alt="Header"
                        className="w-full h-auto"
                        style={{ objectFit: "cover" }}
                    />
                    <div
                        className="absolute bottom-4 flex space-x-2"
                        style={{ transform: "translateX(30px)", left: "4px" }}
                    >
                        <div style={{ display: "flex" }}>
                            <button
                                style={{
                                    backgroundColor: "#00008b",
                                    color: "white",
                                    opacity: 1,
                                    marginRight: "8px",
                                    padding: "8px 12px",
                                }}
                            >
                                Quick Access
                            </button>
                            <button
                                style={{
                                    backgroundColor: "blue",
                                    color: "white",
                                    opacity: 1,
                                    padding: "8px 12px",
                                }}
                            >
                                International Taxation
                            </button>
                        </div>
                    </div>
                </div>
                <div
                    className="mb-4"
                    style={{
                        backgroundColor: "darkblue",
                        color: "white",
                        padding: "10px",
                        borderRadius: "5px",
                    }}
                >
                    <div className="row g-2">
                        <div className="col-md-3">
                            <span>Net Direct Tax collection (provisional) as on 17.09.2024 - [!New]</span>
                            <button
                                className="btn p-0 w-100"
                                onClick={() => handleHeaderLinkClick("tax-collection")}
                                style={{ backgroundColor: "transparent", border: "none" }}
                            >
                                <div className="d-flex align-items-center text-white p-1 rounded">
                                    <img
                                        src={Dis2}
                                        alt="Tax Collection"
                                        className="me-2"
                                    />
                                </div>
                            </button>
                        </div>
                        <div className="col-md-3">
                            <span>Key Highlights of Finance (No. 2) Bill, 2024</span>
                            <button
                                className="btn p-0 w-100"
                                onClick={() => handleHeaderLinkClick("finance-bill")}
                                style={{ backgroundColor: "transparent", border: "none" }}
                            >
                                <div className="d-flex align-items-center text-white p-1 rounded">
                                    <img
                                        src={Dis2}
                                        alt="Finance Bill"
                                        className="me-2"
                                    />
                                </div>
                            </button>
                        </div>
                        <div className="col-md-3">
                            <span>UNION BUDGET 2024-25</span>
                            <button
                                className="btn p-0 w-100"
                                onClick={() => handleHeaderLinkClick("union-budget")}
                                style={{ backgroundColor: "transparent", border: "none" }}
                            >

                                <div className="d-flex align-items-center text-white p-1 rounded">
                                    <img
                                        src={Dis2}
                                        alt="Finance Bill"
                                        className="me-2"
                                    />
                                </div>
                            </button>
                        </div>

                        <div className="col-md-3">
                            <span>Net Direct Tax Collection (provisional) ... (FY) 2024-25</span>
                            <button
                                className="btn p-0 w-100"
                                onClick={() => handleHeaderLinkClick("tax-collection-fy")}
                                style={{ backgroundColor: "transparent", border: "none" }}
                            >
                                <div className="d-flex align-items-center text-white p-1 rounded">
                                    <img
                                        src={Dis2}
                                        alt="Tax Collection FY"
                                        className="me-2"
                                    />
                                </div>
                            </button>
                        </div>
                    </div>
                </div>

                {/* Main Content */}
                <div className="row">
                    {/* Taxable Gratuity Calculator Card */}
                    <div className="col-md-8 mb-4">
                        <div className="card shadow-sm">
                            <div className="card-body">
                                <div className="d-flex justify-content-between align-items-center mb-4">
                                    <div className="d-flex align-items-center">
                                        <h2 className="h4 mb-0" style={{ color: '#00008b' }}>Taxable Gratuity Calculator</h2>
                                        <img
                                            src={Dis}
                                            alt="Info"
                                            className="ms-2"
                                        />
                                    </div>
                                    <div style={{ display: 'flex', justifyContent: 'center', padding: '1px' }}>
                                        <div style={{ padding: '2px' }}>
                                            <span className="me-2" style={{ fontSize: '0.875rem' }}>
                                                <span className="text-danger">*</span> indicates mandatory fields
                                            </span>
                                        </div>
                                        <div className="input-box" style={{
                                            display: 'flex',
                                            alignItems: 'center',
                                            padding: '1px 10px ',
                                            border: '1px solid #ccc',
                                            borderRadius: '4px',
                                            width: 'auto',
                                            maxWidth: '400px',
                                            backgroundColor: '#f9f9f9',
                                        }}>
                                            <button
                                                onClick={handleDisclaimerClick}
                                                className="btn p-0"
                                                style={{
                                                    border: 'none',
                                                    background: 'none',
                                                    display: 'flex',
                                                    alignItems: 'center',
                                                }}
                                            >
                                                <img
                                                    src={Dis1}
                                                    alt="Disclaimer"
                                                    style={{
                                                        height: '30px',
                                                        marginRight: '8px',
                                                    }}
                                                />
                                                Disclaimer
                                            </button>
                                        </div>


                                    </div>
                                </div>

                                <form>
                                    <div className="row mb-3">
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Assessment Year <span className="text-danger">*</span>
                                            </label>
                                            <select className="form-select">
                                                <option>Select year</option>
                                                <option>2026-27</option>
                                                <option>2025-26</option>
                                                <option>2024-25</option>
                                                <option>2023-24</option>
                                                <option>2022-23</option>
                                                <option>2021-22</option>
                                            </select>
                                        </div>
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Type of Employer <span className="text-danger">*</span>
                                            </label>
                                            <select className="form-select">
                                                <option>Select</option>
                                                <option>Centeral/State Goverment</option>
                                                <option>Satutory corp</option>
                                                <option>Local Authority</option>
                                                <optional>other</optional>
                                            </select>
                                        </div>
                                    </div>

                                    <div>
                                        {/* Gratuity Act Checkbox */}
                                        <div className="mb-3">
                                            <div className="form-check">
                                                <input
                                                    type="checkbox"
                                                    className="form-check-input"
                                                    id="gratuityAct"
                                                    checked={isGratuityActChecked}
                                                    onChange={handleGratuityActChange}
                                                />
                                                <label className="form-check-label" htmlFor="gratuityAct">
                                                    Select if covered under payment of gratuity Act, 1972
                                                </label>
                                            </div>
                                        </div>

                                        {/* Piece Rate Checkbox */}
                                        <div className="mb-3">
                                            <div className="form-check">
                                                <input
                                                    type="checkbox"
                                                    className="form-check-input"
                                                    id="pieceRate"
                                                    checked={isPieceRateChecked}
                                                    onChange={handlePieceRateChange}
                                                    disabled={!isGratuityActChecked} // Disable if first checkbox is unchecked
                                                />
                                                <label className="form-check-label" htmlFor="pieceRate">
                                                    Select if wages are based on piece rate
                                                </label>
                                            </div>
                                        </div>

                                        {/* Seasonal Establishment Checkbox */}
                                        <div className="mb-3">
                                            <div className="form-check">
                                                <input
                                                    type="checkbox"
                                                    className="form-check-input"
                                                    id="seasonalEstablishment"
                                                    checked={isSeasonalEstablishmentChecked}
                                                    onChange={handleSeasonalEstablishmentChange}
                                                    disabled={!isGratuityActChecked} // Disable if first checkbox is unchecked
                                                />
                                                <label className="form-check-label" htmlFor="seasonalEstablishment">
                                                    Is seasonal establishment
                                                </label>
                                            </div>
                                        </div>
                                    </div>

                                    <div className="row mb-3">
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Length of service period <span className="text-danger">*</span>
                                            </label>
                                            <input
                                                type="text"
                                                className="form-control mb-2"
                                                placeholder="Enter your service period"
                                                value={servicePeriod}
                                                readOnly
                                            />
                                            <button
                                                type="button"
                                                className="btn btn-link p-0"
                                                onClick={handleCalculateServicePeriod}
                                                style={{ color: '#00008b' }}

                                            >
                                                Calculate Service Period
                                            </button>
                                        </div>
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Gratuity becomes payable on <span className="text-danger">*</span>
                                            </label>

                                            <input type="date" className="form-control" />
                                        </div>
                                    </div>

                                    <div className="row mb-3">
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Average salary of last 10 months <span className="text-danger">*</span>
                                            </label>
                                            <input
                                                type="text"
                                                className="form-control mb-2"
                                                placeholder="Enter your Average salary of last 10 months"
                                                value={averageSalary}
                                                readOnly
                                            />
                                            {/* Button to open the new modal */}
                                            <button
                                                type="button"
                                                className="btn btn-link p-0"
                                                onClick={handleOpenAverageSalaryForm}
                                                style={{ color: '#00008b' }}
                                            >
                                                Calculate Service Average Salary
                                            </button>
                                        </div>
                                        <div className="col-md-6">
                                            <label className="form-label">
                                                Gratuity Received <span className="text-danger">*</span>
                                            </label>
                                            <select className="form-select">
                                                <option>Select</option>
                                            </select>
                                        </div>
                                    </div>


                                    <div className="table-responsive">
                                        <table className="table table-bordered">
                                            <thead className="table-light">
                                                <tr style={{ textAlign: "center" }}>
                                                    <th>
                                                        (1)
                                                        <br />
                                                        Date of arrival to India(a)
                                                    </th>
                                                    <th>
                                                        (2)
                                                        <br />
                                                        Date of departure from India(b)
                                                    </th>
                                                    <th>
                                                        (3)
                                                        <br />
                                                        Total days spent in India(b-a)
                                                    </th>
                                                </tr>
                                            </thead>
                                            <tbody>
                                                <tr>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            placeholder="00/00/0000"
                                                            value={arrivalDate}
                                                            onChange={(e) => setArrivalDate(e.target.value)}
                                                        />
                                                    </td>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            placeholder="00/00/0000"
                                                            value={departureDate}
                                                            onChange={(e) => setDepartureDate(e.target.value)}
                                                        />
                                                    </td>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            placeholder="-"
                                                            disabled
                                                            value={daysSpent}
                                                        />
                                                    </td>
                                                </tr>
                                            </tbody>
                                        </table>
                                    </div>
                                </form>
                            </div>
                        </div>
                    </div>

                    <div className="col-md-4">
                        <div className="card shadow-sm">
                            <div className="card-body">
                                <h3 className="card-title" style={{ color: '#00008b', borderBottom: '1px solid #dee2e6', paddingBottom: '10px' }}>Total,</h3>
                                <div className="mb-3">
                                    <div className="border rounded p-3">
                                        <label className="form-label text-muted mb-1" style={{ color: '#00008b' }}>Exempted gratuity</label>
                                        <div className="text-left"><b>-</b></div>
                                    </div>
                                </div>
                                <div>
                                    <div className="border rounded p-3">
                                        <label className="form-label text-muted mb-1" style={{ color: '#00008b' }}>Taxable gratuity</label>
                                        <div className="text-left"><b>-</b></div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>


            {showServicePeriodForm && (
                <div
                    className="modal"
                    style={{ display: 'block', backgroundColor: 'rgba(0, 0, 0, 0.5)' }}
                >
                    <div className="modal-dialog modal-dialog-centered">
                        <div className="modal-content">
                            <div className="modal-header border-bottom" style={{ width: '80%', margin: '0 auto' }}>
                                <h5 className="modal-title" style={{ color: '#00008b' }}>
                                    Computation of length of service period
                                </h5>
                            </div>
                            <div className="modal-body">
                                <div className="mb-3 position-relative">
                                    <label className="form-label">
                                        Date of joining <span className="text-danger">*</span>
                                    </label>
                                    <input
                                        type="date"
                                        className="form-control"
                                        value={joiningDate}
                                        onChange={(e) => setJoiningDate(e.target.value)}
                                    />
                                </div>
                                <div className="mb-3 position-relative">
                                    <label className="form-label">
                                        Date of retirement <span className="text-danger">*</span>
                                    </label>
                                    <input
                                        type="date"
                                        className="form-control"
                                        value={retirementDate}
                                        onChange={(e) => setRetirementDate(e.target.value)}
                                    />
                                </div>
                                <div className="mb-3">
                                    <div className="service-period-container" style={{ height: '100px', border: '1px solid #ced4da', borderRadius: '4px', padding: '10px' }}>
                                        <label className="form-label" style={{ color: '#00008b' }}>
                                            Length of service period <span className="text-danger">*</span>
                                        </label>
                                        <div className="text-left mt-2">
                                            <span style={{ fontWeight: 'bold', fontSize: '1.2em' }}>
                                                {servicePeriod || '00Y 00M 00D'}
                                            </span>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div className="modal-footer">
                                <button
                                    type="button"
                                    className="btn"
                                    style={{
                                        backgroundColor: 'transparent',
                                        color: '#00008b',
                                        border: '2px solid #00008b',
                                        borderRadius: '5px',
                                        padding: '8px 16px',
                                        fontWeight: 'bold',
                                        boxShadow: '2px 2px 5px rgba(0, 0, 0, 0.1)',
                                        cursor: 'pointer',
                                        fontSize: '16px',
                                    }}
                                    onClick={handleSubmitServicePeriod}
                                >
                                    Submit
                                </button>
                            </div>
                        </div>
                    </div>
                </div>
            )}

            {showAverageSalaryForm && (
                <div
                    className="modal"
                    style={{ display: 'block', backgroundColor: 'rgba(0, 0, 0, 0.5)' }}
                >
                    <div className="modal-dialog modal-dialog-centered modal-lg">
                        <div className="modal-content">
                            <div className="modal-header border-bottom" style={{ width: '80%', margin: '0 auto' }}>
                                <h5 className="modal-title" style={{ color: '#00008b' }}>
                                    Leaves entitled during the service period
                                </h5>

                            </div>

                            <div className="modal-body">
                                <div className="table-responsive mb-4">
                                    <table className="table table-bordered">
                                        <thead className="table-light">
                                            <tr>
                                                <th>(1)<br />Month</th>
                                                <th>(2)<br />Date of arrival in India</th>
                                                <th>(3)<br />Date of departure from India</th>
                                                <th>(4)<br />Total days spent in India</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                            {tenMonthsData.map((row, index) => (
                                                <tr key={index}>
                                                    <td>{row.month}</td>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            placeholder="00/00/0000"
                                                            value={row.arrivalDate}
                                                            onChange={(e) =>
                                                                handleRowChange(index, 'arrivalDate', e.target.value)
                                                            }
                                                        />
                                                    </td>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            placeholder="dd/mm/yyyy"
                                                            value={row.departureDate}
                                                            onChange={(e) =>
                                                                handleRowChange(index, 'departureDate', e.target.value)
                                                            }
                                                        />
                                                    </td>
                                                    <td>
                                                        <input
                                                            type="text"
                                                            className="form-control"
                                                            disabled
                                                            placeholder="0000"
                                                            value={row.daysSpent}
                                                        />
                                                    </td>
                                                </tr>
                                            ))}
                                        </tbody>
                                    </table>
                                </div>

                                <div className="row justify-content-center align-items-center">
                                    <div className="col-md-5">
                                        <div
                                            className="salary-box"
                                            style={{
                                                height: '120px',
                                                border: '1px solid #ced4da',
                                                borderRadius: '4px',
                                                padding: '15px',
                                                marginBottom: '20px'
                                            }}
                                        >
                                            <label className="form-label" style={{ color: '#00008b' }}>
                                                Total salary for 10 months
                                            </label>
                                            <input
                                                type="text"
                                                className="form-control mt-2"
                                                value={totalSalaryFor10Months}
                                                onChange={(e) => setTotalSalaryFor10Months(e.target.value)}
                                                placeholder="000000"
                                                style={{ height: '50px' }}
                                            />
                                        </div>
                                    </div>
                                    <div className="col-md-5">
                                        <div
                                            className="salary-box"
                                            style={{
                                                height: '120px',
                                                border: '1px solid #ced4da',
                                                borderRadius: '4px',
                                                padding: '15px',
                                                marginBottom: '20px'
                                            }}
                                        >
                                            <label className="form-label" style={{ color: '#00008b' }}>
                                                10 months average salary
                                            </label>
                                            <input
                                                type="text"
                                                className="form-control mt-2"
                                                value={averageSalaryFor10Months}
                                                disabled
                                                placeholder="000000"
                                                style={{ height: '50px' }}
                                            />
                                        </div>
                                    </div>
                                </div>
                            </div>

                            <div className="modal-footer">
                                <button
                                    type="button"
                                    className="btn"
                                    style={{
                                        backgroundColor: 'transparent',
                                        color: '#00008b',
                                        border: '2px solid #00008b',
                                        borderRadius: '5px',
                                        padding: '8px 16px',
                                        fontWeight: 'bold',
                                        boxShadow: '2px 2px 5px rgba(0, 0, 0, 0.1)',
                                        cursor: 'pointer',
                                        fontSize: '16px',
                                    }}
                                    onClick={handleSubmitAverageSalary}
                                >
                                    Submit
                                </button>
                            </div>
                        </div>
                    </div>
                </div>
            )}
        </div>
    );
};

export default GratuityCalculator;


// int main() {
//   std::cout << "Hello World!\n";
// }
